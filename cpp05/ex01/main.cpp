#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Form class ===" << std::endl;

    try
    {
        std::cout << "\n--- Test 1: Creating valid forms ---" << std::endl;
        Form basicForm("Basic Form", 100, 100);
        Form importantForm("Important Form", 25, 5);
        std::cout << basicForm << std::endl;
        std::cout << importantForm << std::endl;

        std::cout << "\n--- Test 2: Creating forms with invalid grades ---" << std::endl;
        Form invalidForm("Invalid Form", 0, 50); // Should throw exception
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        Form invalidForm2("Invalid Form 2", 100, 151); // Should throw exception
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 3: Signing forms with adequate grade ---" << std::endl;

        Bureaucrat director("Director", 5);
        Bureaucrat manager("Manager", 30);
        Bureaucrat employee("Employee", 120);

        Form managementForm("Management Form", 20, 10);
        Form employeeForm("Employee Form", 100, 100);

        std::cout << "\nBefore signing:" << std::endl;
        std::cout << managementForm << std::endl;
        std::cout << employeeForm << std::endl;

        director.signForm(managementForm);
        manager.signForm(employeeForm);

        std::cout << "\nAfter signing:" << std::endl;
        std::cout << managementForm << std::endl;
        std::cout << employeeForm << std::endl;

        std::cout << "\n--- Test 4: Signing forms with inadequate grade ---" << std::endl;
        employee.signForm(managementForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 5: Signing an already signed form ---" << std::endl;

        Bureaucrat chief("Chief", 1);
        Bureaucrat assistant("Assistant", 50);

        Form secretForm("Secret Form", 30, 10);

        std::cout << "Initial form state: " << secretForm << std::endl;
        assistant.signForm(secretForm);
        std::cout << "After assistant signing: " << secretForm << std::endl;
        chief.signForm(secretForm); // Should work but not change the form state
        std::cout << "After chief signing: " << secretForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}