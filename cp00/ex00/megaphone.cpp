#include <iostream>

void megaphone(int ac, char **av)
{
	int i = 1;
	int j = 0;
	for (i = 1; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] -= 32;
			std::cout << av[i][j];
		}
	}
	std::cout << "\n";
	return ;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	megaphone(ac, av);
	return (0);
}