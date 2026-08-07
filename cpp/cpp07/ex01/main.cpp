#include "iter.hpp"

void doubling(int &i)
{
	i *= 2;
}

void print(std::string &str)
{
	std::cout << str << std::endl;
}

int main( void )
{
	int int_arr[] = {1, 2, 3};

	::iter(int_arr, 3, doubling);

	for (int i = 0; i < 3; i++)
		std::cout << int_arr[i] << std::endl;

    std::cout << "-----------------------" << std::endl;
    
	std::string str_arr[] = {"Hello", "world", "!!!"};
	::iter(str_arr, 3, print);

	return (0);
}