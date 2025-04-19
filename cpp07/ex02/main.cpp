#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
    // Test with default constructor (empty array)
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // Test with parametrized constructor
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test for deep copy with copy constructor
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    // Check if values are identical with the mirror
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    // Test exception handling with out of bounds access
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught for negative index: " << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught for too large index: " << e.what() << std::endl;
    }

    // Test array with different type
    Array<std::string> strings(5);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "School";
    strings[3] = "C++";
    strings[4] = "Templates";

    std::cout << "String array contents:" << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
    {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    Array<std::string> stringsCopy;
    stringsCopy = strings;

    std::cout << "String copy array contents:" << std::endl;
    for (unsigned int i = 0; i < stringsCopy.size(); i++)
    {
        std::cout << stringsCopy[i] << " ";
    }
    std::cout << std::endl;

    // Check deep copy by modifying original
    strings[0] = "Modified";

    std::cout << "Original after modification: " << strings[0] << std::endl;
    std::cout << "Copy after original modification: " << stringsCopy[0] << std::endl;

    delete[] mirror;
    return 0;
}