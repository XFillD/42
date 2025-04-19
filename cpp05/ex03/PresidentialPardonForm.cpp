#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute),
      target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute),
      target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Execute method
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    // Check if form can be executed
    this->checkExecutability(executor);

    // Inform that the target has been pardoned
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}