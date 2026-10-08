#include <iostream>
#include <memory>

/**
 * Dog class
 */
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


int multiply(int& num) 
{
    auto new_num{num * 2}; // on the stack

    int* temp = new int{1000}; // leaks as object is on the heap

    return new_num;
}


int main() 
{
    int x{100};
    auto y = std::make_unique<int>(multiply(x));

    std::cout << x << std::endl;
    std::cout << *y << std::endl;

    return 0;
}