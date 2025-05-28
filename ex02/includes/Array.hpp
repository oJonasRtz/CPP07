#ifndef ARRAY_HPP
#define ARRAY_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
	private:
		T				*data;
		unsigned int	len;
	public:
		//	Getters
		unsigned int		size(void) const
		{
			return(len);
		}
		const T				*getData(void) const
		{
			return (data);
		}
		
		//	Constructors
		Array(void): data(new T[0]), len(0)
		{
			std::cout << BRIGHT_GREEN "Array: constructor called\n" RESET;
		}
		Array(unsigned int n): data(new T[n]), len(n)
		{
			std::cout << BRIGHT_GREEN "Array: constructor called\n" RESET;
		}
		Array(const Array &other): data(new T[other.size()]), len(other.size())
		{
			std::cout << BRIGHT_GREEN "Array: copy constructor called\n" RESET;
			for (unsigned int i = 0; i < len; i++)
				data[i] = other.data[i];
		}
		Array	&operator=(const Array &other)
		{
			std::cout << BRIGHT_GREEN "Array: assignment operator\n" RESET;
			if (this != &other)
			{
				delete[] data;
				len = other.size();
				data = new T[len];
				for (unsigned int i = 0; i < len; i++)
					data[i] = other.data[i];
			}
			return (*this);
		}
		~Array(void)
		{
			std::cout << BRIGHT_RED "Array: destructor called\n" RESET;
			delete[] data;
		}
		class	ExceptionOutOfBounds: public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return (BRIGHT_RED "Access out of bounds" RESET);
				}
		};

		//	Read operator[]
		const T	&operator[](unsigned int i) const
		{
			if (i >= len)
				throw (ExceptionOutOfBounds());
			return (this->data[i]);
		}
		//	Write operator[]
		T	&operator[](unsigned int i)
		{
			if (i >= len)
				throw (ExceptionOutOfBounds());
			return (this->data[i]);
		}
};

template<typename T>
std::ostream	&operator<<(std::ostream &out, const Array<T> &other)
{
	out << ORANGE "(Array)" <<
		BRIGHT_BLUE " len: " RESET << other.size() <<
		" | " <<
		BRIGHT_BLUE "data: " RESET << other.getData(); 
	return (out);
}

typedef struct s_map
{
	std::string	name;
	void		(*f)(void);
}	t_map;

#endif