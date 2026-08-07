#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(std::string type);

    WrongAnimal(WrongAnimal const &src);
    WrongAnimal&    operator=(WrongAnimal const &src);

    std::string     getType() const;

    void	makeSound() const;
protected:
    std::string type;
};

#endif