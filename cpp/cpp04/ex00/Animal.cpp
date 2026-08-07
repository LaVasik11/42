#include "Animal.hpp"

Animal::Animal() : type("none")
{
	std::cout << "Animal Defaut constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called for " << this->type << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
}

Animal &	Animal::operator=(Animal const &src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}
