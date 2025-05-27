#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = a;

	a = b;
	b = temp;
}

/*
	* returns the smallest value
	* if both are equal return the second value
*/
template<typename T>
T	&min(T &a, T &b)
{
	return (b <= a ? b : a);
}

/*
	* returns the greatest value
	* if both are equal return the second value
*/
template<typename T>
T	&max(T &a, T&b)
{
	return (b >= a ? b : a);
}

typedef struct s_map
{
	std::string	name;
	void		(*f)(void);
}	t_map;

#endif