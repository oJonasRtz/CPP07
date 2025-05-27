#include "iter.hpp"

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

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "How to use: ./iter <test number>\n" RESET;
	return (0);
}

static void	fill(int &a)
{
	a = 2;
}

template<typename T>
static void	print(T a)
{
	std::cout << ORANGE "value: " << RESET << a << std::endl;
}

static void	intTest(void)
{
	drawTitle("Int tests", 1);
	int	*a = new int[10];
	::iter(a, 10, &fill);
	::iter(a, 10, &print<int>);
	delete[] a;
}

static void	fillStr(std::string &s)
{
	s = "Hello world";
}

static void	strTest(void)
{
	drawTitle("string tests", 1);
	std::string	*a = new std::string[10];
	::iter(a, 10, &fillStr);
	::iter(a, 10, &print<std::string>);
	delete[] a;
}

static void	fillStruct(t_test &test)
{
	test.x = 3.14f;
	test.y = 2.71f;
	test.name = "Bob *the builder*";
}

static void	printStruct(t_test &test)
{
	std::cout << ORANGE "name: " << RESET << test.name;
	std::cout << ORANGE " x: " << RESET << test.x;
	std::cout << ORANGE " y: " << RESET << test.y << std::endl;
}

static void	structTest(void)
{
	drawTitle("struct tests", 1);
	t_test	*a = new t_test[10];
	::iter(a, 10, &fillStruct);
	::iter(a, 10, &printStruct);
	delete[] a;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());
	
	const int	len = 3;
	t_map		map[len] =
	{
		{"1", &intTest},
		{"2", &strTest},
		{"3", &structTest},
	};
	for (int i = 0; i < len; i++)
		if (map[i].name == argv[1])
		{
			map[i].f();
			break;
		}
	return (0);
}

