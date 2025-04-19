#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form; // Forward declaration

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // Getters
    const std::string &getName() const;
    int getGrade() const;

    // Grade modifiers
    void incrementGrade();
    void decrementGrade();

    // Form interactions
    void signForm(Form &form);

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP