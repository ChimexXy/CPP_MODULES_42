#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const& x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T& x) {
    ++x;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    std::cout << "--- printing ints ---" << std::endl;
    iter(nums, 5, print<int>);
    
    std::cout << "--- incrementing ints ---" << std::endl;
    iter(nums, 5, increment<int>);
    iter(nums, 5, print<int>);
    
    std::string words[] = {"hello", "templates", "are", "fun"};
    std::cout << "--- printing strings ---" << std::endl;
    iter(words, 4, print<std::string>);
    
    return 0;
}