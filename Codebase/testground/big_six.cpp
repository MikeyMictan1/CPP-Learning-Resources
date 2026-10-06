#include <iostream>
#include <vector>

class Dog {
public:
    Dog(std::string nam, int ag) : name{std::move(nam)}, age{ag} {}

    // Default constructor
    Dog() : name{"Unknown"}, age{0} {}

    const std::string& getName() const { return name; }

    int getAge() const { return age; }

    void setName(const std::string& nam) { name = nam; }

    void printInfo() const { std::cout << "Name: " << name << " Age: " << age << std::endl; }

private:
    std::string name;
    int age;
};

int main() 
{
    // Constructor ------------------------------------------------------------
    Dog peanut;

    // Destructor ------------------------------------------------------------
    {
        Dog temp_doggo("tempeh", 1);
        temp_doggo.printInfo();
    }
    // temp_doggo.printInfo(); compile error: name not visible out here (scope).
    // Separately, its destructor already ran at the } (lifetime).

    // Copy Constructor ------------------------------------------------------------
    Dog a;
    Dog b = a; // 'a' copied into NEW object, 'b'
    /**  
     * 'a' is an object at 700, 'b' is a NEW object at 800 with its own copy of everything.
     * Not linked, so changing one doesn't change the other.
     * (Model assumes a long name. Short names like "Unknown" are stored inside the object: SSO.)
     * 
     * STACK                                        HEAP
     * 700 (a): name{ptr=5000, size=7}              5000: "Unknown"
     *          age = 0
     * 
     * 800 (b): name{ptr=6000, size=7}              6000: "Unknown"
     *          age = 0

    */

    // Copy Assignment Operator ------------------------------------------------------------
    Dog james("James", 4);
    Dog jamie("Jamie", 2);
    jamie = james; // 'james' copied into PRE-EXISTING object, 'jamie'

    // Move constructor ------------------------------------------------------------
    Dog alice("Alice", 3);
    Dog bob = std::move(alice); // Contents of alice moved from alice to bob, different adress, no extra allocation.

    /**
     * 'alice' is an object at 700, 'bob' is a NEW object at 800.
     * bob's name takes over alice's heap buffer (5000). No allocation, no letters copied.
     * alice is still a valid Dog: empty name, age unchanged.
     * 
     * Before ---
     * STACK                                      HEAP
     * 700 (alice):  name{ptr=5000, size=5}       5000: "Alice"
     *               age=3
     * 
     * After ---
     * STACK                                    HEAP
     * 700 (alice): name{EMPTY, size=0}         5000: "Alice"
     *              age = 3
     * 
     * 800 (bob): name{ptr=5000, size=5}        
     *            age = 3

    */

    // Move Assignment Operator ------------------------------------------------------------
    Dog crystal;
    Dog irene;
    irene = std::move(crystal); // crystal's contents moved into PRE-EXISTING object irene

    irene.printInfo();          // Name: Crystal Age: 5
    crystal.printInfo();        // Name:  Age: 5  (empty in practice, not guaranteed)

    return 0;
}