#include <iostream>

struct Animal {
    virtual void speak() const { std::cout << "...\n"; }
    virtual ~Animal() = default;
};

struct Dog : Animal {
    void speak() const override { std::cout << "Woof\n"; }
};

struct Cat : Animal {
    void speak() const override { std::cout << "Meow\n"; }
};

void describe(const Animal& a) { a.speak(); }   // ONE function, no template

int main()
{
    Dog dog;
    Cat cat;

    int choice{};
    std::cout << "1 = dog, 2 = cat: ";
    std::cin >> choice;

    const Animal* pet{ &dog };
    if (choice == 2)
        pet = &cat;

    describe(*pet);   // compiler has no idea if this is a Dog or a Cat
    return 0;
}