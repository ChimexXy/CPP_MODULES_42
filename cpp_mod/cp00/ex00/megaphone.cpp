#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	int j = 0;
	for (i = 1; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			av[i][j] = std::toupper(av[i][j]);
			std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}