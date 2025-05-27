#ifndef ITER_HPP
#define ITER_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

template<typename T, typename F>
void	iter(T *array, unsigned long lengh, F func)
{
	if (!array || lengh == 0)
		return;
	for (unsigned long i = 0; i < lengh; i++)
		func(array[i]);
}

typedef struct s_map
{
	std::string	name;
	void		(*f)(void);
}	t_map;

typedef struct s_test
{
	float	x;
	float	y;
	std::string	name;
}	t_test;

#endif