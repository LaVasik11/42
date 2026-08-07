#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
	~Dog();

	Dog(Dog const &src);
	Dog& operator=(Dog const &src);

    void	makeSound() const;
    Brain* getBrain() const;
private:
    Brain       *brain;
};

#endif