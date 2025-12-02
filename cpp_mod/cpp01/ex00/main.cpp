#include "Zombie.hpp"

int main()
{
	Zombie* heapCall = newZombie("Foo");
	heapCall->call();
	delete heapCall;

	randomChump("chimex");
}