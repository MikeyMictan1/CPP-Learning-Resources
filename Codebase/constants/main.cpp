#include <iostream>

// ---
int aa(int x, int y) { return x + y; }

const int bb(int x, int y) { return x + y; }

constexpr int cc(int x, int y) { return x + y; }
// ---
int& dd(int& x) { 
    x = x * 2;
    return x; 
}

// const int& ee(int& x) { return x * 2; }
// constexpr int& ff(int& x) { return x * 2; }
// ---

int main() 
{
    int a = aa(2,3);
    int b = bb(2,3);
    int c = cc(2,3);

    std::cout << a << std::endl;
}