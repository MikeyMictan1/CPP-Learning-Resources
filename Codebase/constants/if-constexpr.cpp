#include <iostream>
#include <cstddef>

int main() {
    if constexpr (true) {
        return 0;
    } else {
        return std::byte {0x01};
    }
}