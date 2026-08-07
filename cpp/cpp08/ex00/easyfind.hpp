#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include<algorithm>
# include<exception>

class NotFoundExeption : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return ("Number not found");
    }
	
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundExeption();
	return (it);
}

#endif