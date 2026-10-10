#include <iostream>

// ---
int aa(int x, int y) { return x + y; }

const int bb(int x, int y) { return x + y; }

constexpr int cc(int x, int y) { return x + y; }

// ------------------------------------------

int& dd(int& x) { x = x * 2; return x; }

const int& ee(int& x) { x = x * 2; return x; }

constexpr int& ff(int& x) { x = x * 2; return x; }
// ---

int main() 
{
    // if we EVER want to return a constexpr (not necessarily JUST constexpr, but if we ever want one),
    // then as a general rule just put it in the return type.
    int d = 5;
    int e = 5;
    int f = 5;

    d = dd(d); // a is still an int
    e = ee(e); // a is now a const
    f = ff(f); // a is now a constexpr

}
