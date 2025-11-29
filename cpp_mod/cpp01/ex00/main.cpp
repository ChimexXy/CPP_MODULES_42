#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("Foo");
	heapZombie->call();
	delete heapZombie;

	randomChump("Bar");
}