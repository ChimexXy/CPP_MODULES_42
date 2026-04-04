#include "phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook() : ind(0), count(0) {}

std::string line_parser(std::string line)
{
    int i, j;
    for(i = line.length() - 1; i >= 0; i--)
    {
        if(line[i] != ' ')
            break ;
    }
    for(j = 0; line[j]; j++)
    {
        if(line[j] != ' ')
            break ;
    }
    return (line.substr(j, i - j + 1));
}

bool all_digit(std::string line)
{
    int i = 0;
    for(i = 0; line[i]; i++)
    {
        if(!std::isdigit(line[i]))
            return false;
    }
    return true;
}

void Phonebook::add_new_contact()
{
    Contact n_contact;
    std::string line;

    while(1)
    {
        std::cout << "enter the first name : ";
        getline(std::cin, line);
        line = line_parser(line);
        if (line.empty())
        {
            std::cout << "Try Again" << std::endl;
            continue;
        }
        else
        {
            n_contact.set_first_name(line);
            break;
        }
    }

    while(1)
    {
        std::cout << "enter the last name : ";
        getline(std::cin, line);
        line = line_parser(line);
        if (line.empty())
        {
            std::cout << "Try Again" << std::endl;
            continue;
        }
        else
        {
            n_contact.set_last_name(line);
            break;
        }
    }

    while(1)
    {
        std::cout << "enter the nick name : ";
        getline(std::cin, line);
        line = line_parser(line);
        if (line.empty())
        {
            std::cout << "Try Again" << std::endl;
            continue;
        }
        else
        {
            n_contact.set_nick_name(line);
            break;  
        }
    }

    while(1)
    {
        std::cout << "enter the phone number : ";
        getline(std::cin, line);
        line = line_parser(line);
        if (line.empty() || !all_digit(line))
        {
            std::cout << "Try Again" << std::endl;
            continue;
        }
        else
        {
            n_contact.set_phone_number(line);
            break;
        }
    }

    while(1)
    {
        std::cout << "enter your darkest_secret : ";
        getline(std::cin, line);
        line = line_parser(line);
        if (line.empty())
        {
            std::cout << "Try Again" << std::endl;
            continue;
        }
        else
        {
            n_contact.set_darkest_secret(line);
            break;
        }
    }

    contacts[ind] = n_contact;
    ind = (ind + 1) % 8;
    if (count < 8)
        count++;
}

std::string limit_column(std::string str)
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void print_contacts(Contact contact, int index)
{
    std::cout << "|" << std::setw(10) << std::right << index 
              << "|" << std::setw(10) << std::right << limit_column(contact.get_first_name())
              << "|" << std::setw(10) << std::right << limit_column(contact.get_last_name())
              << "|" << std::setw(10) << std::right << limit_column(contact.get_nick_name()) << "|" << std::endl;
}


void Phonebook::search_contact()
{
    if (count == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return ;
    }

    std::cout << "|" << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First_Name"
              << "|" << std::setw(10) << std::right << "Last_Name"
              << "|" << std::setw(10) << std::right << "Nick_name" << "|" << std::endl;

    for(int i = 0; i < count; i++)
        print_contacts(contacts[i], i);
    std::string input;
    int index = -1;
    while(1)
    {
        std::cout << "Entre The index of contact : " << std::endl;
        getline(std::cin, input);
        index = std::atoi(input.c_str());

        if (input.empty()|| input.length() > 1 || index < 0 || index >= count)
        {
            std::cout << "Invalid Index, Try Again :(" << std::endl;
            continue;
        }
        else
            break;
    }
    std::cout << "------->>>>>" << index << std::endl;
    Contact x_contact = contacts[index];
    std::cout << "First Name : " << x_contact.get_first_name() << std::endl; 
    std::cout << "Last Name : " << x_contact.get_last_name() << std::endl; 
    std::cout << "Nick Name : " << x_contact.get_nick_name() << std::endl; 
    std::cout << "Phone Number : " << x_contact.get_phone_number() << std::endl; 
    std::cout << "Darkest Secret : " << x_contact.get_darkest_secret() << std::endl; 
}

int main()
{
    Phonebook phonebook;
    std::string command;
    while(1)
    {
        std::cout << "enter the command : (ADD) (SEARCH) (EXIT)" << std::endl;
        getline(std::cin, command);
        if(command == "ADD")
            phonebook.add_new_contact();
        else if(command == "SEARCH")
            phonebook.search_contact();
        else if(command == "EXIT")
        {
            std::cout << "exit the programme" << std::endl;
            exit (1);
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}
