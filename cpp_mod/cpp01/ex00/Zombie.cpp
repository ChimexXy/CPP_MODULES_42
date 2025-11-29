#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << this->name << ": is destroy" << std::endl;
}

void Zombie::call(void) const{
	std::cout << this->name << ":  BraiinnzzZ" << std::endl;
}
