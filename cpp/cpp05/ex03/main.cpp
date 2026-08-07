#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::srand(std::time(0));

    Intern intern;

    try
    {
        AForm* form;

        form = intern.makeForm(
            "shrubbery creation",
            "home"
        );

        if (form)
        {
            Bureaucrat bob("Bob", 1);

            std::cout << *form << std::endl;

            bob.signForm(*form);

            bob.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form;

        form = intern.makeForm(
            "robotomy request",
            "Bender"
        );

        if (form)
        {
            Bureaucrat alice("Alice", 1);

            alice.signForm(*form);

            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form;

        form = intern.makeForm(
            "presidential pardon",
            "Arthur Dent"
        );

        if (form)
        {
            Bureaucrat president("President", 1);

            president.signForm(*form);

            president.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form;

        form = intern.makeForm(
            "unknown form",
            "target"
        );

        if (form)
            delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form;

        form = intern.makeForm(
            "presidential pardon",
            "Marvin"
        );

        if (form)
        {
            Bureaucrat low("Low", 150);

            low.signForm(*form);

            low.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form;

        form = intern.makeForm(
            "robotomy request",
            "Robot"
        );

        if (form)
        {
            Bureaucrat boss("Boss", 1);

            boss.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}