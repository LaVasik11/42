#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meaouw!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}
