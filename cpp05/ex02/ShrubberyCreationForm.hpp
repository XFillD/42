#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat &executor) const;

    // File creation could fail, so we need an exception
    class FileOpenException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // Static constants for grade requirements
    static const int gradeToSign = 145;
    static const int gradeToExecute = 137;
};

#endif // SHRUBBERYCREATIONFORM_HPP