#include "data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.id = 42;
    original.name = "hello";

    uintptr_t raw = Serializer::serialize(&original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original address:  " << &original << std::endl;
    std::cout << "Restored address:  " << restored << std::endl;
    std::cout << "Same pointer?      " << (&original == restored) << std::endl;
    std::cout << "Restored content:  " << restored->id 
              << ", " << restored->name << std::endl;
    return 0;
}