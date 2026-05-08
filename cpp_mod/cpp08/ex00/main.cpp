#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i <= 5 ; ++i)
        vec.push_back(i);
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}