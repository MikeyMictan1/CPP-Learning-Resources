#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    // 1) reserve: capacity changes, size doesn't
    v.reserve(5);
    std::cout << "after reserve(5): size " << v.size() << " cap " << v.capacity() << '\n';

    // 2) push_back up to capacity: no reallocation, so the data pointer never moves
    const int* before{ v.data() };
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);
    std::cout << "after 5 pushes:   size " << v.size() << " cap " << v.capacity()
              << " moved? " << (v.data() != before) << '\n';

    // 3) one more push goes past capacity: reallocation, old pointers now dangle
    v.push_back(50);
    std::cout << "after 6th push:   size " << v.size() << " cap " << v.capacity()
              << " moved? " << (v.data() != before) << '\n';
    
    std::cout << "We re-allocated, so data has moved, so old pointers dange at old location" << std::endl;

    // 4) reserve smaller than capacity does nothing (never shrinks)
    v.reserve(2);
    std::cout << "after reserve(2): size " << v.size() << " cap " << v.capacity() << '\n';

    return 0;
}



