#include <thread>
#include <atomic>
#include <iostream>

int plain = 0;
std::atomic<int> atomicCounter{0};

void addPlain()  { for (int i = 0; i < 100000; ++i) ++plain; }
void addAtomic() { for (int i = 0; i < 100000; ++i) ++atomicCounter; }

int main() {
    std::thread a(addPlain), b(addPlain);
    a.join(); b.join();
    std::cout << "plain:  " << plain << "\n";          // usually < 200000

    std::thread c(addAtomic), d(addAtomic);
    c.join(); d.join();
    std::cout << "atomic: " << atomicCounter << "\n";  // always 200000
    return 0;
}