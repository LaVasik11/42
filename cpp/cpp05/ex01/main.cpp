#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 10);
        AForm tax("Tax Form20", 20, 30);

        std::cout << bob << std::endl;
        std::cout << tax << std::endl;

        bob.signForm(tax);

        std::cout << tax << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat tom("Tom", 100);
        AForm secret("Tax Form50", 50, 20);

        std::cout << tom << std::endl;
        std::cout << secret << std::endl;

        tom.signForm(secret);

        std::cout << secret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;


    try
    {
        AForm invalid("Invalid", 0, 10);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}