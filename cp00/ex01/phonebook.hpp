#ifndef PHONEBOOK_HPP
#define PHONEBOOk_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
public:
    void set_first_name(std::string first_name);
    void set_last_name(std::string last_name);
    void set_nick_name(std::string nick_name);
    void set_phone_number(std::string phone_number);
    void set_darkest_secret(std::string darkest_secret);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nick_name() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;

};

class Phonebook {
private:
    int ind;
    int count;
    Contact contacts[8];
    
public:
    Phonebook();
    void add_new_contact();
    void search_contact();
};

#endif