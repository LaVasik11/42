#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array&		operator=(const Array& other);
	T&			operator[](unsigned int i);
	const T&	operator[](unsigned int i) const;
	
	unsigned int	size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

private:
	T			*arr;
	unsigned int	_size;
};
#include "Array.tpp"

#endif