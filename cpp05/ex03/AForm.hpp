#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Form functions
    void beSigned(const Bureaucrat &bureaucrat);

    // Execute methods
    virtual void execute(const Bureaucrat &executor) const = 0;
    void checkExecutability(const Bureaucrat &executor) const;

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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // AFORM_HPP