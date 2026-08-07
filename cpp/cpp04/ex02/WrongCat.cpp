#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
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