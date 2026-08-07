#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <fstream>
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

    void execute(Bureaucrat const & executor) const override;
private:
    const std::string   target;

};

#endif