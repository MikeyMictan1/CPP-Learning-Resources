#include <iostream>

constexpr int square(int x) { return x * x; }

int main() 
{
    std::cout << square(5) << std::endl;

    int n;
    std::cin >> n;

    std::cout << square(n) << std::endl;
}