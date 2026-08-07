#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("none")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called for " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "ooo" << std::endl;
}