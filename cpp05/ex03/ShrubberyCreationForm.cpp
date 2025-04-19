#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute),
      target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute),
      target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    // Check if form can be executed
    this->checkExecutability(executor);

    // Create ASCII tree in a file
    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open())
    {
        throw ShrubberyCreationForm::FileOpenException();
    }

    // ASCII tree
    outfile << "         *         " << std::endl;
    outfile << "        ***        " << std::endl;
    outfile << "       *****       " << std::endl;
    outfile << "      *******      " << std::endl;
    outfile << "     *********     " << std::endl;
    outfile << "    ***********    " << std::endl;
    outfile << "   *************   " << std::endl;
    outfile << "  ***************  " << std::endl;
    outfile << " ***************** " << std::endl;
    outfile << "*******************" << std::endl;
    outfile << "        |||        " << std::endl;
    outfile << "        |||        " << std::endl;

    outfile.close();

    std::cout << "Created shrubbery in file: " << filename << std::endl;
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Error: Could not open or create the output file";
}