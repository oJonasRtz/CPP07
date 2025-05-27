#include "whatever.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(30, '=') << "\n\t" << title << "\n" << std::string(30, '=') << RESET << std::endl;
	else
		std::cout << std::string(30, '=') << "\n\t" << title << "\n" << std::string(30, '=') << std::endl;
}

template<typename T>
static void	drawValues(T &a, T &b)
{
	std::cout << ORANGE "a: " << a << " b: " << b << RESET << std::endl;
}

static void	swapTests(void)
{
	drawTitle("Swap tests", 1);

	drawTitle("int values", 0);
	int	a = 10;
	int	b = 20;
	drawValues(a, b);
	::swap(a, b);
	drawValues(a, b);

	drawTitle("std::string values", 0);
	std::string	c = "Hello world";
	std::string	d = "Goodbye world";
	drawValues(c, d);
	::swap(c, d);
	drawValues(c, d);

	drawTitle("char values", 0);
	char	e = 'c';
	char	f = 'd';
	drawValues(e, f);
	::swap(e, f);
	drawValues(e, f);

	drawTitle("double values", 0);
	double	g = 3.14;
	double	h = 2.71;
	drawValues(g, h);
	::swap(g, h);
	drawValues(g, h);
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "How to use: ./whatever <test number>\n" RESET;
	return (0);
}

static void	minTests(void)
{
	drawTitle("Min tests", 1);

	drawTitle("int values", 0);
	int	a = 10;
	int	b = 20;
	drawValues(a, b);
	std::cout << BRIGHT_GREEN "The minor value is " RESET << ::min(a, b) << std::endl;

	drawTitle("std::string values", 0);
	std::string	c = "Hello world";
	std::string	d = "world";
	drawValues(c, d);
	std::cout << BRIGHT_GREEN "The minor value is " RESET << ::min(c, d) << std::endl;

	drawTitle("char values", 0);
	char	e = 'c';
	char	f = 'd';
	drawValues(e, f);
	std::cout << BRIGHT_GREEN "The minor value is " RESET << ::min(e, f) << std::endl;

	drawTitle("double values", 0);
	double	g = 3.14;
	double	h = 2.71;
	drawValues(g, h);
	std::cout << BRIGHT_GREEN "The minor value is " RESET << ::min(g, h) << std::endl;

	drawTitle("equals", 0);
	int	lala = 30;
	int	lele = 30;
	drawValues(lala, lele);
	std::cout << ORANGE "Second address: " RESET << &lele << std::endl;
	int	&l = ::min(lala, lele);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << l << std::endl;
	std::cout << ORANGE "Return address: " RESET << &l << std::endl;
}

static void	maxTests(void)
{
	drawTitle("Max tests", 1);

	drawTitle("int values", 0);
	int	a = 10;
	int	b = 20;
	drawValues(a, b);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << ::max(a, b) << std::endl;

	drawTitle("std::string values", 0);
	std::string	c = "Hello world";
	std::string	d = "world";
	drawValues(c, d);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << ::max(c, d) << std::endl;

	drawTitle("char values", 0);
	char	e = 'c';
	char	f = 'd';
	drawValues(e, f);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << ::max(e, f) << std::endl;

	drawTitle("double values", 0);
	double	g = 3.14;
	double	h = 2.71;
	drawValues(g, h);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << ::max(g, h) << std::endl;

	drawTitle("equals", 0);
	int	lala = 30;
	int	lele = 30;
	drawValues(lala, lele);
	std::cout << ORANGE "Second address: " RESET << &lele << std::endl;
	int	&l = ::max(lala, lele);
	std::cout << BRIGHT_GREEN "The greatest value is " RESET << l << std::endl;
	std::cout << ORANGE "Return address: " RESET << &l << std::endl;
}

static void	subjectTest(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << ORANGE "a = " RESET << a << ORANGE ", b = " RESET << b << std::endl;
	std::cout << ORANGE "min( a, b ) = " RESET << ::min( a, b ) << std::endl;
	std::cout << ORANGE "max( a, b ) = " RESET << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << ORANGE "c = " RESET << c << ORANGE ", d = " RESET << d << std::endl;
	std::cout << ORANGE "min( c, d ) = " RESET << ::min( c, d ) << std::endl;
	std::cout << ORANGE "max( c, d ) = " RESET << ::max( c, d ) << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());
	
	const int	len = 4;
	t_map		map[len] =
	{
		{"1", &swapTests},
		{"2", &minTests},
		{"3", &maxTests},
		{"4", &subjectTest}
	};
	for (int i = 0; i < len; i++)
		if (map[i].name == argv[1])
		{
			map[i].f();
			break;
		}
	return (0);
}

