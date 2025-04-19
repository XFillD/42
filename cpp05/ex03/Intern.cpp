#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Orthodox Canonical Form implementations
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other; // Unused parameter
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other; // Unused parameter
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

// Form creation method
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    // Array of form names
    static const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    // Function pointer type for form creation
    typedef AForm *(Intern::*FormCreator)(const std::string &);

    // Array of form creation methods
    static const FormCreator creators[3] = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm};

    // Find matching form name
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            AForm *form = (this->*creators[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }

    // Form name not found
    throw Intern::UnknownFormException();
    return NULL;
}

// Helper methods for each form type (private)
AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

// Exception method
const char *Intern::UnknownFormException::what() const throw()
{
    return "Error: Unknown form name";
}