#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

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

private:
	std::vector<int>	vec;
	std::deque<int>		deq;
};

#endif