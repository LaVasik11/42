#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cstddef>


struct FJItem
{
    int value;
    size_t id;
};

struct FJPair
{
    FJItem small;
    FJItem large;
};


class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& other);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& other);

	std::vector<int>	vec_misort(const std::vector<int>& arr);
	std::deque<int>		deq_misort(const std::deque<int>& arr);
	void				sortVector();
	void				sortDeque();

	const std::vector<int>&	get_vector() const;
	const std::deque<int>&	get_deque() const;
	size_t					getVectorComparisons() const;
	size_t					getDequeComparisons() const;

private:
	std::vector<int>	vec;
	std::deque<int>		deq;
	size_t				vecComparisons;
	size_t				deqComparisons;
};

#endif