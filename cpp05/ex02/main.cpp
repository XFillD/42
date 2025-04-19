#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Testing Concrete Forms ===" << std::endl;

        // Create bureaucrats with different grades
        Bureaucrat president("President", 1);
        Bureaucrat minister("Minister", 20);
        Bureaucrat assistant("Assistant", 70);
        Bureaucrat intern("Intern", 140);

        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;

        // Try to execute before signing
        std::cout << "\n--- Trying to execute before signing ---" << std::endl;
        president.executeForm(shrubForm);

        // Sign and execute
        std::cout << "\n--- Signing and executing ---" << std::endl;
        intern.signForm(shrubForm);
        president.executeForm(shrubForm);

        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robotForm("targetX");
        std::cout << robotForm << std::endl;

        // Try with insufficient grade
        std::cout << "\n--- Trying with insufficient grade ---" << std::endl;
        intern.signForm(robotForm);       // Should work
        assistant.executeForm(robotForm); // Should fail - grade too low

        // Try with sufficient grade
        std::cout << "\n--- Trying with sufficient grade ---" << std::endl;
        minister.executeForm(robotForm); // Should work

        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardonForm("criminal");
        std::cout << pardonForm << std::endl;

        // Try with insufficient grade to sign
        std::cout << "\n--- Trying with insufficient grade to sign ---" << std::endl;
        assistant.signForm(pardonForm); // Should fail - grade too low

        // Sign properly and execute
        std::cout << "\n--- Signing properly and executing ---" << std::endl;
        minister.signForm(pardonForm);     // Should work
        minister.executeForm(pardonForm);  // Should fail - grade too low
        president.executeForm(pardonForm); // Should work
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}