#include "Array.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(30, '=') << "\n\t" << title << "\n" << std::string(30, '=') << RESET << std::endl;
	else
		std::cout << std::string(30, '=') << "\n\t" << title << "\n" << std::string(30, '=') << std::endl;
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "How to use: ./array <test number>\n" RESET;
	return (0);
}
template<typename T>
static void	drawArray(const char &c, const Array<T> &a)
{
	std::cout << ORANGE << c << ": " RESET << a << std::endl;
}

static void	testOrtodox(void)
{
	drawTitle("Canonical Ortodox Form", 1);
	drawTitle("Constructors", 0);
	Array<int>			a(10);
	Array<int>			b;
	Array<char*>		c(5);
	Array<std::string>	d(7);
	Array<std::string>	cpyD(d);
	Array<int>			cpyA(a);
	Array<char*>		cpyC(c);

	drawTitle("Operator <<", 0);
	char	letter = 'a';
	drawArray(letter++, a);
	drawArray(letter++, b);
	drawArray(letter++, c);
	drawArray(letter, d);
	drawTitle("Operator << (copies)", 0);
	drawArray('a', cpyA);
	drawArray('c', cpyC);
	drawArray('d', cpyD);

	drawTitle("Assignment operator", 0);
	drawArray('a', a);
	a = b;
	drawArray('a', a);

	drawTitle("destructors", 0);
}

static void	squareBracketsTest(void)
{
	drawTitle("Square brackets []", 1);
	drawTitle("Write test", 0);
	Array<int>			a(1);
	Array<std::string>	b(1);
	try{
		//Valid write
		a[0] = 42;
		b[0] = "Hello world";

		//Exception
		a[1] = 84;
	}catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	drawTitle("Read test", 0);
	std::cout << ORANGE "a: " RESET << a[0] << std::endl;
	std::cout << ORANGE "b: " RESET << b[0] << std::endl;
	try{
		std::cout << ORANGE "b: " RESET << b[4] << std::endl;
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	drawTitle("destructors", 0);
}

static void	cpyTest(void)
{
	drawTitle("Copy test", 1);
	Array<int>	a(5);
	Array<int>	b;

	try{
		drawArray('a', a);
		drawArray('b', b);

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i + 1;
		
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << ORANGE "a[" << i << "] = " RESET << a[i] << std::endl;
		
		//	this is an exception for test porpouses
		std::cout << ORANGE "b[0] = " RESET << b[0] << std::endl;
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		b = a;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << ORANGE "b[" << i << "] = " RESET << b[i] << std::endl;

		drawArray('a', a);
		drawArray('b', b);
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	drawTitle("Copy constructor", 0);
	Array<int>	c(a);
	try{
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << ORANGE "c[" << i << "] = " RESET << c[i] << std::endl;
	}catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	drawArray('a', a);
	drawArray('c', c);

	drawTitle("destructors", 0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	const int	len = 3;
	t_map		map[len] =
	{
		{"1", &testOrtodox},
		{"2", &squareBracketsTest},
		{"3", &cpyTest},
	};
	for (int i = 0; i < len; i++)
		if (map[i].name == argv[1])
		{
			map[i].f();
			break;
		}
	return (0);
}

