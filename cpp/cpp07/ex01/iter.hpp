#ifndef ITER_HPP
#define ITER_HPP

# include<iostream>

template<typename array_type, typename func_type>
void	iter(array_type *array, size_t len, func_type func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif