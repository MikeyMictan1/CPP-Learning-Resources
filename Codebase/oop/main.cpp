#include <iostream>
#include <memory>
#include <vector>

class Animal {
public:
    virtual void speak() const { std::cout << "Animal\n"; }
    void greet() const { std::cout << "Animal greet\n"; } // NOT virtual
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
    void greet() const { std::cout << "Dog greet\n"; } // hides, doesn't override
};

void byValue(Animal a) { a.speak(); } // slices
void byRef(const Animal& a) { a.speak(); }

int main()
{
    Dog d;
    Animal& a = d;

    a.speak(); // Woof         -> dynamic type, through the vtable
    a.greet(); // Animal greet -> static type, direct call

    byValue(d); // Animal -> sliced copy, vptr is Animal's
    byRef(d);   // Woof

    std::cout << sizeof(Animal) << "\n"; // 8 -> just the vptr

    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>());
    zoo.push_back(std::make_unique<Animal>());
    for (const auto& x : zoo) x->speak(); // Woof, Animal
} // unique_ptr deletes through Animal* -> safe only because ~Animal is virtual