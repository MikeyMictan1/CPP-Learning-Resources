#include <iostream>
#include <memory>

int main() 
{
    int x = 100;
    int* z;

    // Move logic
    auto a = std::make_unique<int>(10); // a (ptr to 10 in heap) in stack location Y, 10 in heap at location X
    auto b = std::move(a); // b (ptr to 10 in heap) in stack location Z, 10 in heap at location X

    auto c = 100; // 100 in stack at location X.
    auto d = std::move(c); // 100 now in stack at location Y AND X. move same as copy here.

    {
        int y = 10;
        z = &y;
    }

    std::cout << x + *z << std::endl; // UB
    
    return 0;
}