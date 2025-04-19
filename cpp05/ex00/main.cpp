#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Bureaucrat class ===" << std::endl;

    try
    {
        std::cout << "\n--- Test 1: Valid bureaucrat ---" << std::endl;
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;

        std::cout << "\n--- Test 2: Increment grade ---" << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "\n--- Test 3: Decrement grade ---" << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;

        std::cout << "\n--- Test 4: Grade too high ---" << std::endl;
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade(); // Should throw exception
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 5: Grade too low ---" << std::endl;
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
        charlie.decrementGrade(); // Should throw exception
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 6: Invalid grade at creation (too high) ---" << std::endl;
        Bureaucrat david("David", 0); // Should throw exception
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 7: Invalid grade at creation (too low) ---" << std::endl;
        Bureaucrat eve("Eve", 151); // Should throw exception
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}