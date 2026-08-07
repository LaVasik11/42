#include "Cat.hpp"

Cat::Cat() : Animal::Animal("Cat")
{
	this->type = Animal::getType();
	std::cout << "Cat Defaut constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal::Animal(src)
{
	*this = src;
}

Cat &	Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meaouw!" << std::endl;
}