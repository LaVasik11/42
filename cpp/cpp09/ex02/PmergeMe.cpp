#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :  vecComparisons(0), deqComparisons(0) {}

PmergeMe::PmergeMe(int argc, char **argv) : vecComparisons(0), deqComparisons(0)
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
		vecComparisons = other.vecComparisons;
		deqComparisons = other.deqComparisons;
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

size_t PmergeMe::getVectorComparisons() const
{
    return (vecComparisons);
}

size_t PmergeMe::getDequeComparisons() const
{
    return (deqComparisons);
}

std::vector<size_t> jacobsthal_sequence(size_t n)
{
    std::vector<size_t>	seq;
    size_t				prev = 1;
    size_t				curr = 3;

    while (prev < n + 1)
    {
        size_t end = curr;

        if (end > n + 1)
            end = n + 1;

        for (size_t i = end; i > prev; --i)
            seq.push_back(i - 2);

        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return (seq);
}

size_t find_item(const std::vector<FJItem>& chain, size_t id)
{
    for (size_t i = 0; i < chain.size(); ++i)
    {
        if (chain[i].id == id)
            return (i);
    }

    return (chain.size());
}

void binary_insert(std::vector<FJItem>& chain, const FJItem& item, size_t paired_id, size_t& comparisons)
{
    size_t left = 0;
    size_t right = find_item(chain, paired_id);

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        ++comparisons;

        if (chain[mid].value < item.value)
            left = mid + 1;
        else
            right = mid;
    }

    chain.insert(chain.begin() + left, item);
}

std::vector<FJItem> ford_johnson(const std::vector<FJItem>& arr, size_t& comparisons)
{
    if (arr.size() <= 1)
        return (arr);

    std::vector<FJPair>	pairs;
    std::vector<FJItem>	larges;
    FJItem				straggler;
    bool				has_straggler = false;

    pairs.reserve(arr.size() / 2);

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        FJPair pair;

        ++comparisons;

        if (arr[i].value < arr[i + 1].value)
        {
            pair.small = arr[i];
            pair.large = arr[i + 1];
        }
        else
        {
            pair.small = arr[i + 1];
            pair.large = arr[i];
        }

        pairs.push_back(pair);
        larges.push_back(pair.large);
    }

    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        has_straggler = true;
    }

    std::vector<FJItem>	sorted_larges = ford_johnson(larges, comparisons);
    std::vector<FJPair>	sorted_pairs;

    sorted_pairs.reserve(pairs.size());

    for (size_t i = 0; i < sorted_larges.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].large.id == sorted_larges[i].id)
            {
                sorted_pairs.push_back(pairs[j]);
                break;
            }
        }
    }

    std::vector<FJItem> main_chain;
    std::vector<FJPair> pend;

    if (!sorted_pairs.empty())
    {
        main_chain.push_back(sorted_pairs[0].small);

        for (size_t i = 0; i < sorted_larges.size(); ++i)
            main_chain.push_back(sorted_larges[i]);

        for (size_t i = 1; i < sorted_pairs.size(); ++i)
            pend.push_back(sorted_pairs[i]);
    }

    std::vector<size_t> order = jacobsthal_sequence(pend.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t index = order[i];

        if (index < pend.size())
            binary_insert(main_chain, pend[index].small, pend[index].large.id, comparisons);
    }

    if (has_straggler)
        binary_insert(main_chain, straggler, main_chain.size(), comparisons);

    return (main_chain);
}

void PmergeMe::sortVector()
{
    std::vector<FJItem> items;

    items.reserve(vec.size());

    for (size_t i = 0; i < vec.size(); ++i)
    {
        FJItem item;

        item.value = vec[i];
        item.id = i;

        items.push_back(item);
    }

    std::vector<FJItem>	sorted = ford_johnson(items, vecComparisons);
    std::vector<int>	result;

    result.reserve(sorted.size());

    for (size_t i = 0; i < sorted.size(); ++i)
        result.push_back(sorted[i].value);

    vec = result;
}

size_t find_item(const std::deque<FJItem>& chain, size_t id)
{
    for (size_t i = 0; i < chain.size(); ++i)
    {
        if (chain[i].id == id)
            return (i);
    }

    return (chain.size());
}

void binary_insert(std::deque<FJItem>& chain, const FJItem& item,
    size_t paired_id, size_t& comparisons)
{
    size_t left = 0;
    size_t right = find_item(chain, paired_id);

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        ++comparisons;

        if (chain[mid].value < item.value)
            left = mid + 1;
        else
            right = mid;
    }

    chain.insert(chain.begin() + left, item);
}

std::deque<FJItem> ford_johnson(const std::deque<FJItem>& arr,
    size_t& comparisons)
{
    if (arr.size() <= 1)
        return (arr);

    std::deque<FJPair> pairs;
    std::deque<FJItem> larges;
    FJItem straggler;
    bool has_straggler = false;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        FJPair pair;

        ++comparisons;

        if (arr[i].value < arr[i + 1].value)
        {
            pair.small = arr[i];
            pair.large = arr[i + 1];
        }
        else
        {
            pair.small = arr[i + 1];
            pair.large = arr[i];
        }

        pairs.push_back(pair);
        larges.push_back(pair.large);
    }

    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        has_straggler = true;
    }

    std::deque<FJItem> sorted_larges = ford_johnson(larges, comparisons);
    std::deque<FJPair> sorted_pairs;

    for (size_t i = 0; i < sorted_larges.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].large.id == sorted_larges[i].id)
            {
                sorted_pairs.push_back(pairs[j]);
                break;
            }
        }
    }

    std::deque<FJItem> main_chain;
    std::deque<FJPair> pend;

    if (!sorted_pairs.empty())
    {
        main_chain.push_back(sorted_pairs[0].small);

        for (size_t i = 0; i < sorted_larges.size(); ++i)
            main_chain.push_back(sorted_larges[i]);

        for (size_t i = 1; i < sorted_pairs.size(); ++i)
            pend.push_back(sorted_pairs[i]);
    }

    std::vector<size_t> order = jacobsthal_sequence(pend.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t index = order[i];

        if (index < pend.size())
        {
            binary_insert(main_chain, pend[index].small,
                pend[index].large.id, comparisons);
        }
    }

    if (has_straggler)
        binary_insert(main_chain, straggler, main_chain.size(), comparisons);

    return (main_chain);
}

void PmergeMe::sortDeque()
{
    std::deque<FJItem> items;

    for (size_t i = 0; i < deq.size(); ++i)
    {
        FJItem item;

        item.value = deq[i];
        item.id = i;

        items.push_back(item);
    }

    std::deque<FJItem> sorted = ford_johnson(items, deqComparisons);
    std::deque<int> result;

    for (size_t i = 0; i < sorted.size(); ++i)
        result.push_back(sorted[i].value);

    deq = result;
}