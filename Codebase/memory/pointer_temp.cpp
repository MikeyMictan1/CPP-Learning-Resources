#include <iostream>
#include <memory>

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

int main()
{
    // Making a new object on the heap, with pointer to it on the stack
    int* num1 = new int{100};
    auto num2 = std::make_unique<int>(101);

    std::cout << *num1 << std::endl;
    std::cout << *num2 << std::endl;
    delete num1;

    // Make the object first, then make the pointer
    int num3 = 100;
    int* num3_ptr = &num3;
    std::unique_ptr<int> num3_smart_ptr(&num3);

    // --------------------------------------------------------
    int* num = new int{500};
    std::cout << num << std::endl; // address of the int on the HEAP
    std::cout << *num << std::endl; // actual value
    std::cout << &num << std::endl; // address of the pointer on the STACK

    std::unique_ptr<Dog> peanut = std::make_unique<Dog>("Peanut", 3);
    std::cout << peanut.get() << std::endl; // address of Dog on the HEAP
    std::cout << (*peanut).getName() << std::endl; // actual peanut values
    std::cout << &peanut << std::endl; // address if the pointer on the STACK
    return 0;
} 