#include "Form.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : \
    name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), \
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return (*this);
}

const std::string& AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << \
    ", signed: " << form.getIsSigned() << \
    ", grade to sign: " << form.getGradeToSign() << \
    ", grade to execute: " << form.getGradeToExecute();

    return (os);
}