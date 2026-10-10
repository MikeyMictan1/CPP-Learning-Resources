#include <cstddef>   // std::size_t
#include <utility>   // std::swap, std::move

template <typename T>
class SharedPtr {
    T* ptr_ = nullptr;
    std::size_t* count_ = nullptr;     // the "control block", just a heap counter

    void release() {
        if (count_ && --*count_ == 0) {
            delete ptr_;
            delete count_;
        }
        ptr_ = nullptr;
        count_ = nullptr;
    }

public:
    SharedPtr() = default;
    explicit SharedPtr(T* p) : ptr_(p), count_(new std::size_t(1)) {}
    ~SharedPtr() { release(); }

    // copy: share and bump
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
        if (count_) ++*count_;
    }

    // move: steal, leave the source empty, count unchanged
    SharedPtr(SharedPtr&& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    // one operator handles copy-assign and move-assign (copy-and-swap)
    SharedPtr& operator=(SharedPtr other) noexcept {
        swap(other);
        return *this;
    }

    void swap(SharedPtr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(count_, other.count_);
    }

    void reset() { release(); }
    void reset(T* p) { SharedPtr(p).swap(*this); }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    T* get() const { return ptr_; }
    std::size_t use_count() const { return count_ ? *count_ : 0; }
    explicit operator bool() const { return ptr_ != nullptr; }
};