#ifndef PHONEBOOK_HPP
#define PHONEBOOk_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class phonebook{
public:
    int count;
    std::string command;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
};
#endif