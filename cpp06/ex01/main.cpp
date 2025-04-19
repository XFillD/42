#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    // Create a Data structure with some values
    Data original;
    original.id = 42;
    original.name = "Test Data";
    original.value = 3.14;
    
    // Print the original pointer and values
    std::cout << "Original pointer: " << &original << std::endl;
    std::cout << "Original values: id=" << original.id
              << ", name=" << original.name
              << ", value=" << original.value << std::endl;
    
    // Serialize the pointer to an integer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize the integer back to a pointer
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    
    // Print the deserialized values to verify they match
    std::cout << "Deserialized values: id=" << deserialized->id
              << ", name=" << deserialized->name
              << ", value=" << deserialized->value << std::endl;
    
    // Verify that the pointers are the same
    if (deserialized == &original)
        std::cout << "SUCCESS: Deserialized pointer matches the original!" << std::endl;
    else
        std::cout << "ERROR: Deserialized pointer does not match the original!" << std::endl;
    
    return 0;
}