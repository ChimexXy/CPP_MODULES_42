#include "Base.hpp"

int main() {
    std::srand(std::time(NULL));
	Base* obj = generate();
	Base* obj1 = generate();
	Base* obj2 = generate();
	
	std::cout << "PTR: " << std::endl;

	identify(obj);
	identify(obj1);
	identify(obj2);

	std::cout << "REF: " << std::endl;

	identify(*obj);
	identify(*obj1);
	identify(*obj2);

	delete obj;
	delete obj1;
	delete obj2;

	return 0;
}