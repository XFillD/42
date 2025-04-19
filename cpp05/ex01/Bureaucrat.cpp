#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor with exception handling
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other)
    {
        // Cannot assign to const name
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getters
const std::string &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

// Grade modifiers
void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
    std::cout << "Grade incremented to " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
    std::cout << "Grade decremented to " << this->grade << std::endl;
}

// Form interactions
void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Exception methods
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: Grade too high (min grade is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: Grade too low (max grade is 150)";
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}