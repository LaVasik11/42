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
    void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan();
	int		longestSpan();

	class ContainerIsFullException : public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};

    class TooFewNumbersException : public std::exception
    {
        public:
            virtual const char *what() const noexcept;
    };
private:
    unsigned int		max_size;
    std::vector<int>	vect;
};

#endif