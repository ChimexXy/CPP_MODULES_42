#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other._templates[i])
            this->_templates[i] = other._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        // Delete old templates
        for (int i = 0; i < 4; i++) {
            if (this->_templates[i]) {
                delete this->_templates[i];
                this->_templates[i] = NULL;
            }
        }
        
        // Copy new templates
        for (int i = 0; i < 4; i++) {
            if (other._templates[i])
                this->_templates[i] = other._templates[i]->clone();
            else
                this->_templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) {
            delete this->_templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
    
    // Find first empty slot
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] == NULL) {
            this->_templates[i] = m;
            std::cout << "Learned materia: " << m->getType() << std::endl;
            return;
        }
    }
    
    // Can't learn more - delete it to prevent leak
    std::cout << "MateriaSource is full! Cannot learn more." << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type) {
            std::cout << "Creating materia: " << type << std::endl;
            return this->_templates[i]->clone();  // Return a copy!
        }
    }
    
    std::cout << "Unknown materia type: " << type << std::endl;
    return NULL;
}