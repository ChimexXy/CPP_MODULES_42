#include "phonebook.hpp"

Phonebook::Phonebook() : ind(0), count(0) {} 

bool is_all_spaces(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isspace(str[i]))
            return false;
    }
    return true;
}

void Phonebook::add_new_contact()
{
    Contact x_contact;
    std::string line;

    std::cout << "enter the first name : ";
    getline(std::cin, line);
    if (line.empty() || is_all_spaces(line))
        return ;
    x_contact.set_first_name(line);

    std::cout << "enter the last name : ";
    getline(std::cin, line);
    if (line.empty() || is_all_spaces(line))
        return ;
    x_contact.set_last_name(line);

    std::cout << "enter the nick name : ";
    getline(std::cin, line);
    if (line.empty() || is_all_spaces(line))
        return ;
    x_contact.set_nick_name(line);

    std::cout << "enter the phone number : ";
    getline(std::cin, line);
    if (line.empty() || is_all_spaces(line))
        return ;
    x_contact.set_phone_number(line);

    std::cout << "enter your darkest_secret : ";
    getline(std::cin, line);
    if (line.empty() || is_all_spaces(line))
        return ;
    x_contact.set_darkest_secret(line);

    contacts[ind] = x_contact;
    ind = (ind + 1) % 8;
    if (count < 8)
        count++;
    std::cout << ind << std::endl;
}


int main()
{
    Phonebook phonebook;
    std::string command;
    while(1)
    {
        std::cout << "enter the command" << std::endl;
        getline(std::cin, command);
        if(command == "ADD")
            phonebook.add_new_contact();
        else if(command == "SEARCH")
            std::cout << "search the contact" << std::endl;
        else if(command == "EXIT")
        {
            std::cout << "exit the programme" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}
