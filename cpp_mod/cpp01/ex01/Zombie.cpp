#include "Zombie.hpp"

Zombie::Zombie(){

}

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << this->name << ": Is destroy" << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}

void Zombie::call(void) const{
	std::cout << this->name << ": BrainnnzzZ" << std::endl;
}
