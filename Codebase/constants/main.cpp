#include <iostream>

int aa(int x, int y) { return x + y; }

const int bb(int x, int y) { return x + y; }

constexpr int cc(int x, int y) { return x + y; }

int main() 
{
    int a = aa(2,3);

    int b = bb(2,3);

    int c = cc(2,3);

    std::cout << a << std::endl;
}




/**  ---

int& dd(int x, int y) { return x + y; }

const int& ee(int x, int y) { return x + y; }

constexpr int& ff(int x, int y) { return x + y; }
*/