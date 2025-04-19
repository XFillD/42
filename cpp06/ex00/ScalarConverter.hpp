#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    // Private constructor and destructor to prevent instantiation
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

public:
    static void convert(const std::string &literal);
};

#endif // SCALARCONVERTER_HPP