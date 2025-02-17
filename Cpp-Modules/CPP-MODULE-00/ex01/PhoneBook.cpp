/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:30 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:07:30 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; i++)
        _contacts[i] = Contact();
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::ft_add_contact(Contact contact, int index)
{
    _contacts[index] = contact;
}

void PhoneBook::ft_print_all_contacts(void)
{
    string first_name, last_name, nickname;

    std::cout << "╔═════════╦══════════╦══════════╦══════════╗" << std::endl;
    std::cout << "║  Index  ║First Name║ Last Name║  Nickname║" << std::endl;
    std::cout << "╠═════════╬══════════╬══════════╬══════════╣" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        first_name = _contacts[i].get_first_name();
        last_name = _contacts[i].get_last_name();
        nickname = _contacts[i].get_nickname();
        std::cout << "║    " << i << "    ║";
        if (first_name.length() > 10)
            std::cout << first_name.substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << first_name << "|";
        if (last_name.length() > 10)
            std::cout << last_name.substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << last_name << "|";
        if (nickname.length() > 10)
            std::cout << nickname.substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << nickname << "|";
        std::cout << std::endl;
    }
    std::cout << "╚═════════╩══════════╩══════════╩══════════╝" << std::endl << std::endl;
    
}

void PhoneBook::ft_print_contact(const string &str)
{
    int index = std::stoi(str);
    std::cout << "First Name: " << _contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << _contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << _contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].get_darkest_secret() << std::endl;
}

bool PhoneBook::ft_is_number(const string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool PhoneBook::ft_is_valid_number(const string &str)
{
    int number = std::stoi(str);
    return number >= 0 && number < 8;
}

bool PhoneBook::ft_all_spaces(const string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    }
    return true;
}
