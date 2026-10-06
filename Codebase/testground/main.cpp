#include <iostream>
#include <vector>

int main() 
{
    // ------------------------- Pointers and References -------------------------------------------
    int a = 100;
    int* point = &a; // Holds a's address
    int& ref = a; // Is ref the same as a? a copy? duplicate? where doe sit live in memory vs a?

    std::cout << &a     << "\n";  // a's address
    std::cout << point  << "\n";  // same value: the address stored in point
    std::cout << &point << "\n";  // different: point's own address
    std::cout << &ref   << "\n";  // same as &a (holds a's address)
    
    
    // ----------------------

    std::vector<int> listy = {1, 3, 5};

    for (auto& x : listy) {
        std::cout << x << std::endl;
    }

    return 0;

}