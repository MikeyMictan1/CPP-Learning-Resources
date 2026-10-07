#include <iostream>

void clear(int*& p) { p = nullptr; }

int main()
{
    int* int_point = new int{1000};

    std::cout << int_point << std::endl;
    clear(int_point);
    std::cout << int_point << std::endl;

    return 0;
}