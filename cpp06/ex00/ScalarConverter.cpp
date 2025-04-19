#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <string>
#include <iomanip>

// Private constructor and destructor implementation
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }

// Helper function to check if the string is a character literal
static bool isChar(const std::string &literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

// Helper function to check if the string represents a number
static bool isNumber(const std::string &literal)
{
    size_t i = 0;
    bool hasDigits = false;
    bool hasDecimal = false;
    bool hasF = false;

    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    for (; i < literal.length(); i++)
    {
        if (std::isdigit(literal[i]))
            hasDigits = true;
        else if (literal[i] == '.' && !hasDecimal)
            hasDecimal = true;
        else if (literal[i] == 'f' && i == literal.length() - 1 && !hasF)
            hasF = true;
        else
            return false;
    }

    return hasDigits;
}

// Helper function to check if the string is a special value
static bool isSpecial(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convert(const std::string &literal)
{
    // Handle char literal ('c')
    if (isChar(literal))
    {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    // Handle special literals (nan, inf, etc.)
    if (isSpecial(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    // Handle numeric literals
    if (isNumber(literal))
    {
        // Convert to double first
        double d;
        if (literal[literal.length() - 1] == 'f')
            d = std::atof(literal.substr(0, literal.length() - 1).c_str());
        else
            d = std::atof(literal.c_str());

        // Convert to char
        std::cout << "char: ";
        if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
            std::cout << "impossible" << std::endl;
        else if (d < 32 || d > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

        // Convert to int
        std::cout << "int: ";
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d) || std::isinf(d))
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(d) << std::endl;

        // Convert to float
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

        // Convert to double
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    // If we get here, conversion is impossible
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}