#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << " ";
}

template <typename T>
void multiply(T const &x)
{
    T &nonConstRef = const_cast<T &>(x);
    nonConstRef *= 2;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "42", "World"};

    std::cout << "Original int array: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    iter(intArray, 5, multiply);

    std::cout << "Modified int array: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, print);
    std::cout << std::endl;

    return 0;
}