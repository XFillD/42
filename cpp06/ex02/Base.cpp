#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Base destructor implementation
Base::~Base() {}

// Generate a random instance of A, B, or C and return it as a Base pointer
Base *generate(void)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random = std::rand() % 3;
    
    switch (random)
    {
        case 0:
            std::cout << "Generated class A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated class B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated class C" << std::endl;
            return new C();
        default:
            return NULL; // Should never happen
    }
}

// Identify the type using a pointer and dynamic_cast
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identify the type using a reference and dynamic_cast
// Note: cannot use pointers inside this function
void identify(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast &) {}
    
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast &) {}
    
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::bad_cast &) 
    {
        std::cout << "Unknown type" << std::endl;
    }
}