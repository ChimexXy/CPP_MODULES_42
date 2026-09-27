#include "Array.hpp"

#include <iostream>

int main()
{
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); ++i)
        arr[i] = i * 7;

    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

    try
    {
        std::cout << "Accessing out of bounds: " << arr[3] << std::endl;
    } 
    catch (const Array<int>::OutOfBoundsException& e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;

}