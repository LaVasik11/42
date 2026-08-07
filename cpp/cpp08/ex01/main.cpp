#include "Span.hpp"

int	main()
{
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	try
	{
		sp1.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------" << std::endl;
	std::vector<int>	arr;

	for (int i = 0; i < 1000000; i++)
	{
		arr.push_back(i);
	}

	Span sp2(1000000);

	sp2.addNumber(arr.begin(), arr.end());

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try
	{
		sp2.addNumber(arr.begin(), arr.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}