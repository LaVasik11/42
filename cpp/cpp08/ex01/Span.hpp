#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();

	class ContainerIsFullException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

    class TooFewNumbersException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
private:
    unsigned int		max_size;
    std::vector<int>	vect;
};

#endif