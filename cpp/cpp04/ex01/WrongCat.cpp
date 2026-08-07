#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WrongCat")
{
	this->type = WrongAnimal::getType();
	std::cout << "WrongCat Defaut constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal::WrongAnimal(src)
{
	*this = src;
}

WrongCat &	WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meaouw???" << std::endl;
}