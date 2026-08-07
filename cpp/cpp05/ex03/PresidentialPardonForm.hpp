#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <fstream>
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

    void execute(Bureaucrat const & executor) const override;
private:
    const std::string   target;

};

#endif