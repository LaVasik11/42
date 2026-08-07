#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	int	value;

	for (int i = 1; i < argc; i++)
	{
		value = std::atoi(argv[i]);

		vec.push_back(value);
		deq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}


const std::vector<int>&	PmergeMe::get_vector() const
{
	return (vec);
}

const std::deque<int>&	PmergeMe::get_deque() const
{
	return (deq);
}

void PmergeMe::sortVector()
{
	vec = vec_misort(vec);
}

void PmergeMe::sortDeque()
{
	deq = deq_misort(deq);
}

template <typename Container>
static void binary_insert(Container& chain, int value)
{
	typename Container::iterator it =
		std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(it, value);
}

static std::vector<size_t> jacobsthal_sequence(size_t n)
{
	std::vector<size_t> seq;
	if (n == 0)
		return (seq);

	std::vector<size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < n)
	{
		size_t sz = jacob.size();
		size_t next = jacob[sz - 1] + 2 * jacob[sz - 2];
		jacob.push_back(next);
	}

	std::vector<bool> used(n, false);

	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t idx = jacob[i];
		if (idx > n)
			idx = n;
		if (idx > 0 && !used[idx - 1])
		{
			seq.push_back(idx - 1);
			used[idx - 1] = true;
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (!used[i])
			seq.push_back(i);
	}

	return (seq);
}

std::vector<int> PmergeMe::vec_misort(const std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return (arr);

	std::vector<int>					main_chain;
	std::vector<int>					pend;
	std::vector<std::pair<int, int> >	pairs;
	bool								has_straggler = false;
	int									straggler = 0;

	pairs.reserve(arr.size() / 2 + 1);

	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
		{
			if (arr[i] < arr[i + 1])
				pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
			else
				pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
		else
		{
			has_straggler = true;
			straggler = arr[i];
		}
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	if (main_chain.size() > 1)
		main_chain = vec_misort(main_chain);

	std::vector<size_t> order = jacobsthal_sequence(pend.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		if (order[i] < pend.size())
			binary_insert(main_chain, pend[order[i]]);
	}

	if (has_straggler)
		binary_insert(main_chain, straggler);

	return (main_chain);
}

std::deque<int> PmergeMe::deq_misort(const std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return (arr);

	std::deque<int>						main_chain;
	std::deque<int>						pend;
	std::vector<std::pair<int, int> >	pairs;
	bool								has_straggler = false;
	int									straggler = 0;

	pairs.reserve(arr.size() / 2 + 1);

	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
		{
			if (arr[i] < arr[i + 1])
				pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
			else
				pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
		else
		{
			has_straggler = true;
			straggler = arr[i];
		}
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	if (main_chain.size() > 1)
		main_chain = deq_misort(main_chain);

	std::vector<size_t> order = jacobsthal_sequence(pend.size());

	for (size_t i = 0; i < order.size(); i++)
	{
		if (order[i] < pend.size())
			binary_insert(main_chain, pend[order[i]]);
	}

	if (has_straggler)
		binary_insert(main_chain, straggler);

	return (main_chain);
}