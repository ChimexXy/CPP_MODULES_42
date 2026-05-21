#include "BitcoinExchange.hpp"

#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
    BitcoinExchange exchange;

    if (argc != 2)
    {
        std::cerr << "Error: usage: ./btc <input_file>" << std::endl;
        return (1);
    }
    try
    {
        exchange.loadDatabase("data.csv");
        exchange.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}