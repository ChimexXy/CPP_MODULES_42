#include "phonebook.hpp"

void add(phonebook x)
{
    std::cout << "enter the first.name" << std::endl;
    getline(std::cin, x.first_name);
    std::cout << x.first_name << std::endl;

    std::cout << "enter the last name" << std::endl;
    getline(std::cin, x.last_name);
    std::cout << x.last_name << std::endl;

    std::cout << "enter the nick name" << std::endl;
    getline(std::cin, x.nick_name);
    std::cout << x.nick_name << std::endl;

    std::cout << "enter the phone number" << std::endl;
    getline(std::cin, x.phone_number);
    std::cout << x.phone_number << std::endl;

    std::cout << "enter your darkest_secret" << std::endl;
    getline(std::cin, x.darkest_secret);
    std::cout << x.darkest_secret << std::endl;
}

int main()
{
    phonebook x;
    x.count = 0;
    while(1)
    {
        
        std::cout << "enter the command" << std::endl;
        getline(std::cin, x.command);
        if(x.command == "ADD")
            add(x);
        else if(x.command == "SEARCH")
            std::cout << "search the contact" << std::endl;
        else if(x.command == "EXIT")
        {
            std::cout << "exit the programme" << std::endl;
            exit(1);
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}
