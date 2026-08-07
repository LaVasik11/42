#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    virtual ~AForm();

    AForm& operator=(const AForm& other);

    const std::string&  getName() const;
    bool                getIsSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    void    beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    void checkExecution(const Bureaucrat& executor) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const noexcept;
    };
    
    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const noexcept;
    };

private:
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif