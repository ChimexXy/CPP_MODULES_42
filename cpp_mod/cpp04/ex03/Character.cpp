#include "Character.hpp"

Character::Character() : _name("unnamed"), _floorCount(0) {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    for (int i = 0; i < _floorSize; i++) {
        this->_floor[i] = NULL;
    }
}

Character::Character(std::string const & name) : _name(name), _floorCount(0) {
    std::cout << "Character constructor called: " << _name << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    for (int i = 0; i < _floorSize; i++) {
        this->_floor[i] = NULL;
    }
}

Character::Character(const Character& other) : _name(other._name), _floorCount(0) {
    std::cout << "Character copy constructor called" << std::endl;
    
    // Initialize inventory
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();  // Deep copy!
        else
            this->_inventory[i] = NULL;
    }
    
    // Initialize floor
    for (int i = 0; i < _floorSize; i++) {
        this->_floor[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        
        // Delete old inventory
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        
        // Deep copy new inventory
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called: " << _name << std::endl;
    
    // Delete inventory
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
        }
    }
    
    // Delete floor
    for (int i = 0; i < _floorCount; i++) {
        if (this->_floor[i]) {
            delete this->_floor[i];
        }
    }
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
    
    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    
    // Inventory full - drop to floor
    std::cout << _name << "'s inventory is full! Materia dropped to floor." << std::endl;
    if (_floorCount < _floorSize) {
        _floor[_floorCount++] = m;
    } else {
        std::cout << "Floor is full! Deleting materia to prevent leak." << std::endl;
        delete m;
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory index: " << idx << std::endl;
        return;
    }
    
    if (this->_inventory[idx] == NULL) {
        std::cout << "Slot " << idx << " is already empty" << std::endl;
        return;
    }
    
    std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
    
    // Drop to floor (DON'T delete it!)
    if (_floorCount < _floorSize) {
        _floor[_floorCount++] = _inventory[idx];
    }
    
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory index: " << idx << std::endl;
        return;
    }
    
    if (this->_inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    
    this->_inventory[idx]->use(target);
}