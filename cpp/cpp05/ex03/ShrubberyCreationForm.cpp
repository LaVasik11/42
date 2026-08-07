#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{

    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);

    std::ofstream outputFile((this->target + "_shrubbery").c_str());
    if (!outputFile.is_open())
        return ;
    outputFile << "   *\n";
    outputFile << "  /|\\\n";
    outputFile << " / | \\\n";
    outputFile << "/__|__\\\n";
    outputFile << "   |\n";
    outputFile.close();
}