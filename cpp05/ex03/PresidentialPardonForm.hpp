#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat &executor) const;

    // Static constants for grade requirements
    static const int gradeToSign = 25;
    static const int gradeToExecute = 5;
};

#endif // PRESIDENTIALPARDONFORM_HPP