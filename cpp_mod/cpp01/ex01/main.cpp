#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* but = zombieHorde(N, "zombieHorde");
	for (int i = 0; i < N; i++)
		but[i].call();
	delete[] but;
	return 0;
}