#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Defaut constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}
    
Brain::Brain(Brain const &src)
{
	*this = src;
}

Brain &Brain::operator=(Brain const &src)
{
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

