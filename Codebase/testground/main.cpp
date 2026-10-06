#include <iostream>
#include <vector>

class Dog {
public:
    Dog(std::string nam, int ag) : name{std::move(nam)}, age{ag} {}

    const std::string& getName() const { return name; }
    int getAge() const { return age; }

    void setName(const std::string& nam)
    {
        name = nam;
    }

private:
    std::string name;
    int age;
};

int main() 
{
    // ------------------------- Pointers and References -------------------------------------------
    int a = 100;
    int* point = &a; // Holds a's address
    int& ref = a; // Is ref the same as a? a copy? duplicate? where doe sit live in memory vs a?

    std::cout << &a     << "\n";  // a's address
    std::cout << point  << "\n";  // same value: the address stored in point
    std::cout << &point << "\n";  // different: point's own address
    std::cout << &ref   << "\n";  // same as &a (holds a's address)
    
    
    // ----------------------

    std::vector<int> listy = {1, 3, 5};

    for (auto& x : listy) {
        std::cout << x << std::endl;
    }

    // ------------------------------

    Dog peanut("peanut", 10);
    std::cout << peanut.getName() << std::endl;
    std::cout << peanut.getAge() << std::endl;

    // ------------------------------

    const std::string temp_name = "Crysmastree";
    peanut.setName(temp_name);
    std::cout << peanut.getName() << std::endl;
    std::cout << temp_name << std::endl;

    return 0;

}

