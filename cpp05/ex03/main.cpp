#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Testing Intern Class ===" << std::endl;

        // Create intern and bureaucrats
        Intern someRandomIntern;
        Bureaucrat president("President", 5);
        Bureaucrat manager("Manager", 45);

        // Test creating different forms
        std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", "garden");

        std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
        AForm *robotForm = someRandomIntern.makeForm("robotomy request", "Bender");

        std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");

        // Test unknown form type
        std::cout << "\n--- Testing Unknown Form Type ---" << std::endl;
        try
        {
            AForm *unknownForm = someRandomIntern.makeForm("unknown form type", "target");
            delete unknownForm; // Should not reach here
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test using the created forms
        std::cout << "\n=== Using Created Forms ===" << std::endl;

        // Sign and execute shrub form
        std::cout << "\n--- Testing Shrubbery Form ---" << std::endl;
        manager.signForm(*shrubForm);
        manager.executeForm(*shrubForm);

        // Sign and execute robotomy form
        std::cout << "\n--- Testing Robotomy Form ---" << std::endl;
        manager.signForm(*robotForm);
        manager.executeForm(*robotForm);

        // Sign and execute presidential pardon form
        std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
        manager.signForm(*pardonForm);
        manager.executeForm(*pardonForm);   // Should fail - manager's grade too low
        president.executeForm(*pardonForm); // Should work

        // Clean up allocated memory
        std::cout << "\n=== Cleanup ===" << std::endl;
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}