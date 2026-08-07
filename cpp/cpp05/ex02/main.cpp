#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(0));

    try
    {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;

        bob.signForm(shrub);

        shrub.execute(bob);

        std::cout << "Shrubbery created\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 1);

        RobotomyRequestForm robot("Bender");

        alice.signForm(robot);

        robot.execute(alice);
        robot.execute(alice);
        robot.execute(alice);
        robot.execute(alice);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat president("President", 1);

        PresidentialPardonForm pardon("Marvin");

        president.signForm(pardon);

        pardon.execute(president);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm form("garden");

        form.execute(boss);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat low("Low", 150);

        PresidentialPardonForm form("Target");

        low.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 150);

        RobotomyRequestForm form("Robot");

        signer.signForm(form);

        form.execute(executor);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        AForm* form = new ShrubberyCreationForm("");

        std::cout << *form << std::endl;

        delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat chief("Chief", 1);

        AForm* forms[3];

        forms[0] = new ShrubberyCreationForm("forest");
        forms[1] = new RobotomyRequestForm("C3PO");
        forms[2] = new PresidentialPardonForm("Arthur");

        for (int i = 0; i < 3; i++)
        {
            chief.signForm(*forms[i]);

            forms[i]->execute(chief);

            delete forms[i];
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}