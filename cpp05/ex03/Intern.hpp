#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm; // Forward declaration

class Intern
{
private:
    // Helper methods for creating specific form types
    AForm *makeShrubberyCreationForm(const std::string &target);
    AForm *makeRobotomyRequestForm(const std::string &target);
    AForm *makePresidentialPardonForm(const std::string &target);

public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // Form creation method
    AForm *makeForm(const std::string &formName, const std::string &target);

    // Exception for unknown form
    class UnknownFormException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif // INTERN_HPP