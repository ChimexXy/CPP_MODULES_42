#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
}

void Zombie::call(void) const{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << ": is destroy" << std::endl;
}

