#include <iostream>

// Compile time polymorphism functions
void describe(int x)    { std::cout << "int: " << x << '\n'; }
void describe(double x) { std::cout << "double: " << x << '\n'; }

template <typename T>
void describe2(T x) { std::cout << "value: " << x << '\n'; }

int main() 
{
    // Compile Time Polymorphism --------------------------------------------
    // 1) (OVERLOADING)
    describe(5);     // 5 is an int     -> compiler picks describe(int)
    describe(2.5);   // 2.5 is a double -> compiler picks describe(double)

    // 2) (TEMPLATES)
    describe2(5);     // 5 is an int     -> compiler picks describe(int)
    describe2(2.5);   // 2.5 is a double -> compiler picks describe(double)

    return 0;
}