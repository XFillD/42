#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute),
      target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute),
      target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Execute method
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    // Check if form can be executed
    this->checkExecutability(executor);

    // Make drilling noises and attempt robotomy
    std::cout << "* DRILLING NOISES * Brrrr... Bzzzzt... Whirrrr..." << std::endl;

    // Seed the random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // 50% chance of success
    if (std::rand() % 2)
    {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << this->target << " failed." << std::endl;
    }
}