#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));
    
    for (int i = 0; i < 5; ++i) {
        Base* obj = generate();
        std::cout << "Pointer:   ";
        identify(obj);
        std::cout << "Reference: ";
        identify(*obj);
        delete obj;
    }
    return 0;
}