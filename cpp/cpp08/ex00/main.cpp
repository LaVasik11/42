#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "----------vector----------" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << "----------list----------" << std::endl;
	std::list<int> l;
	for (int i = 0; i < 100; i++)
		l.push_back(i);
	try
	{
		std::cout << *easyfind(l, 0) << std::endl;
		std::cout << *easyfind(l, 10000) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << "----------deque----------" << std::endl;
	std::deque<int> d;
	for (int i = 0; i < 3; i++)
		d.push_back(i * 3);
	try
	{
		std::cout << *easyfind(d, 6) << std::endl;
		std::cout << *easyfind(d, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}