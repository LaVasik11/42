#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string&  getName() const;
    int                 getGrade() const;

    void    incrementGrade();
    void    decrementGrade();

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

private:
    const std::string name;
    int               grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif