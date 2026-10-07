#include <iostream>

/**
 * Dog class
 */
class Dog {
public:
    Dog(std::string nam, int ag) : name{std::move(nam)}, age{ag} {}
    Dog() {}

    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    void setName(const std::string& nam) { name = nam; }

private:
    std::string name;
    int age;
};

/**
 * Entrypoint
 */
int main() 
{
    return 0;
}