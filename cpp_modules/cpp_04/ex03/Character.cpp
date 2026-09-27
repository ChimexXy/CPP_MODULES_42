#include "Character.hpp"

Character::Character()
{
    Name = "chimex";
    FloorCount = 0;
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->Inventory[i] = NULL;
    }
    for (int i = 0; i < FloorSize; i++) {
        this->Floor[i] = NULL;
    }
}

Character::Character(std::string const & name)
{
    Name = name;
    FloorCount = 0;
    std::cout << "Character constructor called: " << Name << std::endl;
    for (int i = 0; i < 4; i++) {
        this->Inventory[i] = NULL;
    }
    for (int i = 0; i < FloorSize; i++) {
        this->Floor[i] = NULL;
    }
}

Character::Character(const Character& other)
{
    this->Name = other.Name;
    FloorCount = 0;
    std::cout << "Character copy constructor called" << std::endl;

    for (int i = 0; i < 4; i++) {
        if (other.Inventory[i])
            this->Inventory[i] = other.Inventory[i]->clone();
        else
            this->Inventory[i] = NULL;
    }
    for (int i = 0; i < FloorSize; i++) {
        this->Floor[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) 
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->Name = other.Name;

        // Delete old inventory
        for (int i = 0; i < 4; i++) {
            if (this->Inventory[i]) {
                delete this->Inventory[i];
                this->Inventory[i] = NULL;
            }
        }
        
        // Deep copy new inventory
        for (int i = 0; i < 4; i++) {
            if (other.Inventory[i])
                this->Inventory[i] = other.Inventory[i]->clone();
            else
                this->Inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() 
{
    std::cout << "Character destructor called: " << Name << std::endl;
    
    // Delete inventory
    for (int i = 0; i < 4; i++) {
        if (this->Inventory[i]) {
            delete this->Inventory[i];
        }
    }
    
    // Delete floor
    for (int i = 0; i < FloorCount; i++) {
        if (this->Floor[i]) {
            delete this->Floor[i];
        }
    }
}

std::string const & Character::getName() const 
{
    return this->Name;
}

void Character::equip(AMateria* m) 
{
    if (!m) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (this->Inventory[i] == NULL) {
            this->Inventory[i] = m;
            std::cout << Name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    // Inventory full - drop to floor
    std::cout << Name << "'s inventory is full! Materia dropped to floor." << std::endl;
    if (FloorCount < FloorSize)
        Floor[FloorCount++] = m;
    else
    {
        std::cout << "Floor is full! Deleting materia to prevent leak." << std::endl;
        delete m;
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid inventory index: " << idx << std::endl;
        return;
    }
    
    if (this->Inventory[idx] == NULL)
    {
        std::cout << "Slot " << idx << " is already empty" << std::endl;
        return;
    }
    
    std::cout << Name << " unequipped " << Inventory[idx]->getType() << " from slot " << idx << std::endl;

    if (FloorCount < FloorSize)
        Floor[FloorCount++] = Inventory[idx];
    
    Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid inventory index: " << idx << std::endl;
        return;
    }
    if (this->Inventory[idx] == NULL)
    {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    
    this->Inventory[idx]->use(target);
}