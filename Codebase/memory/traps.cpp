#include <iostream>

// Pointer value itself passed
void clear(int* p) { p = nullptr; }

int main()
{
    int* int_point = new int{1000};

    std::cout << int_point << std::endl; // location e.g. 0x8000
    clear(int_point);
    std::cout << int_point << std::endl; // location NOT CLEARED so still 0x8000

    return 0;
}
