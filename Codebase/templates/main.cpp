#include <iostream>

// Function Template
template <typename T>
T maxOf(T a, T b)
{
    return (a > b) ? a : b;
}

struct Point { int x; int y; };

// Class Template
template <typename T>
class Pair
{
public:
    Pair(T first, T second) : m_first{ first }, m_second{ second } {}

    T first() const { return m_first; }   // defined inside the class
    T larger() const;                     // declared here, defined below

    static inline int s_count{ 0 };       // C++17: one separate copy PER instantiation

private:
    T m_first;
    T m_second;
};

int main()
{
    // FUNCTION TEMPLATE LOGIC ----------------------------
    std::cout << maxOf(3, 7) << '\n';                                         // T deduced as int
    std::cout << maxOf(2.5, 1.5) << '\n';                                     // T deduced as double
    std::cout << maxOf(std::string{ "apple" }, std::string{ "pear" }) << '\n'; // T deduced as std::string
    std::cout << maxOf<double>(3, 7.5) << '\n';                               // T given explicitly, 3 converts to 3.0

    // CLASS TEMPLATE LOGIC -------------------------------
    return 0;
}