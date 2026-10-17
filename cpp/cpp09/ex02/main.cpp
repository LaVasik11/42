#include "PmergeMe.hpp"
#include <ctime>

void print_vector(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe 			pmerge(argc, argv);
		
		std::cout << "Before: ";
		print_vector(pmerge.get_vector());
		std::cout << "After: ";

		clock_t start = std::clock();
		pmerge.sortVector();
		clock_t	end = std::clock();
		double	time_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
		print_vector(pmerge.get_vector());
		std::cout << "Time to process a range of " << pmerge.get_vector().size() << " elements with std::[vector] " << time_us << " us" << std::endl;
		std::cout << "Vector comparisons: " << pmerge.getVectorComparisons() << std::endl;


		start = std::clock();
		pmerge.sortDeque();
		end = std::clock();
		time_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
		std::cout << "Time to process a range of " << pmerge.get_deque().size() << " elements with std::[deque] " << time_us << " us" << std::endl;
		std::cout << "Deque comparisons: " << pmerge.getDequeComparisons() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}
