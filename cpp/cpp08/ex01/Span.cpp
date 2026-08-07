#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        max_size = other.max_size;
        vect = other.vect;
    }
    return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (vect.size() >= max_size)
		throw ContainerIsFullException();
	vect.push_back(n);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vect.size() + std::distance(begin, end) > max_size)
		throw ContainerIsFullException();
	vect.insert(vect.end(), begin, end);
}

int Span::shortestSpan()
{
	if (vect.size() <= 1)
		throw TooFewNumbersException();
	std::vector<int> tmp = vect;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if ((tmp[i] - tmp[i - 1]) < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (vect.size() <= 1)
		throw TooFewNumbersException();
	std::vector<int> tmp = vect;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}


const char* Span::ContainerIsFullException::what() const noexcept
{
	return ("Container is full");
}

const char* Span::TooFewNumbersException::what() const noexcept
{
	return ("Too few Numbers");
}