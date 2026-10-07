#include <iostream>
#include <memory>

class Dog {
public:
    Dog(std::string nam, int ag) : name{std::move(nam)}, age{ag} {}
    Dog() : name{"doggo"}, age{0} {} // default ctor

    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    void setName(const std::string& nam) { name = nam; }
    void printInfo() const { std::cout << "Name: " << name << " | Age: " << age << std::endl; }

private:
    std::string name;
    int age;
};

int main() 
{
    // Unique Pointer ----------------------------------
    std::unique_ptr<Dog> peanut = std::make_unique<Dog>("Peanut", 3);
    auto crystal = std::make_unique<Dog>(); // auto also works, and default ctor used here

    // Shared Pointer ----------------------------------
    std::shared_ptr<Dog> a = std::make_shared<Dog>(); // a.use_count() == 1
    auto b = a;                         // copy: use_count() == 2
    auto c = std::move(a);              // move: use_count() == 2. a == null_ptr()
    b.reset();                          // reset: use_count() == 1
    c.reset();                          // use_count() == 0, dtor runs

    // Weak Pointer ----------------------------------
    std::weak_ptr<Dog> weak;
    {
        auto strong = std::make_shared<Dog>(); // strong 1
        weak = strong;                         // strong 1, weak 1
        if (auto temp = weak.lock()) {         // alive: strong 2 inside this block
            // use temp -> safely here
        }                           
    }                                          // strong 0, dtor runs
    bool gone = weak.expired();                // true
    auto temp = weak.lock();                   // null

    // make_unique and make_shared
    // turning a pointer into a new pointer
    Dog* raw = new Dog;
    std::unique_ptr<Dog> newthing(raw);

    raw->printInfo();

    // Auto ----------------------------------
    Dog d("Peanut", 3);
    auto n1 = d.getName();         // std::string. A COPY, even though getName returns const std::string&
    const auto& n2 = d.getName();  // const std::string&. No copy.

    return 0;
}