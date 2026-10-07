#include <iostream>

struct Order {
    Order()  { std::cout << "ctor\n"; }
    ~Order() { std::cout << "dtor\n"; }
};

int main() 
{
    // a IS the object, created on the stack. automatically cleaned at closing
    Order a; 

    // new returns an adress so compile error for the commented line below
    /* Order b = new Order; */
    
    // pointer c on the stack with address to Order in the heap. 
    // When it goes out of scope, pointer is freed, NOT the object.
    Order* c = new Order; 

    // d points to the right num of bytes with garbage in them, but doesn't make one, so
    // d -> anything won't compile.
    Order* d = (Order*)std::malloc(sizeof(Order));

    // Unique pointer e to the object in the heap. When we go out of scope, both are freed + deleted
    std::unique_ptr<Order> e = std::make_unique<Order>();

    return 0;
}