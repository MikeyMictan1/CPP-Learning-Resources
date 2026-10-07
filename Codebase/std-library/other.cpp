#include <iostream>
#include <vector>

int main()
{
    int x{ 1 };
    int y{ 2 };
    auto f = [x, &y](int z) { return x + y + z; };
    std::cout << f(3) << std::endl; // 1 + 2 + 3 = 6
    return 0;
}