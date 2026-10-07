#include <iostream>
#include <string>
#include <utility>

// DEEP copy, with no copy constructor written.
// The compiler's copy calls std::string's copy, which allocates a new buffer.
class Dog {
public:
    Dog(std::string nam, int ag) : name{std::move(nam)}, age{ag} {}
    Dog() {}

    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    void setName(const std::string& nam) { name = nam; }

private:
    std::string name;
    int age;
};

// SHALLOW copy, with no copy constructor written.
// The compiler's copy copies the pointer, which is just an address.
class Buffer {
public:
    Buffer() : data{new int[3]{1, 2, 3}} {}   // default ctor: the only place new runs
    ~Buffer() { delete[] data; }

    int* data;
};

int main()
{
    // ---------------- Dog: deep ----------------
    Dog a{"Bartholomew the Magnificent III", 3};
    Dog b = a;   // compiler-generated copy ctor

    std::cout << "a letters at: " << static_cast<const void*>(a.getName().data()) << "\n";
    std::cout << "b letters at: " << static_cast<const void*>(b.getName().data()) << "\n";

    b.setName("Sir Reginald Fluffington the Second");
    std::cout << "a name: " << a.getName() << "\n";
    std::cout << "b name: " << b.getName() << "\n\n";

    // ---------------- Buffer: shallow ----------------
    {
        Buffer x;
        Buffer y = x;   // compiler-generated copy ctor

        std::cout << "x data at: " << x.data << "\n";
        std::cout << "y data at: " << y.data << "\n";

        y.data[0] = 99;
        std::cout << "x.data[0]: " << x.data[0] << "\n";

        std::cout << "leaving scope..." << std::endl;
    }   // y's destructor frees the buffer, then x's destructor frees it again

    std::cout << "survived (don't count on it)\n";
    return 0;
}