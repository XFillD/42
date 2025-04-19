#include "Base.hpp"
#include <iostream>

int main()
{
    // Generate a random instance
    Base *randomInstance = generate();
    
    // Identify the type using pointer
    std::cout << "Identifying using pointer: ";
    identify(randomInstance);
    
    // Identify the type using reference
    std::cout << "Identifying using reference: ";
    identify(*randomInstance);
    
    // Clean up allocated memory
    delete randomInstance;
    
    return 0;
}