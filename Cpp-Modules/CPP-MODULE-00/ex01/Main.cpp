/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:19:28 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:16:16 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    string command;

    int i = 0;
    int contact_index = -1;

    while (42)
    {
            std::cout << "Welcome to the phonebook!" << std::endl;
            
        labelStart:
            std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
            std::getline(std::cin, command);
            std::cout << std::endl;
            
            if (command == "EXIT")
            {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            else if (command == "ADD")
            {
                Contact contact;
                
                string _first_name, _last_name, _nickname, _phone_number, _darkest_secret;

            labelFN:
                std::cout << "Enter first name: ";
                std::getline(std::cin, _first_name);

                if (_first_name == "" || phonebook.ft_all_spaces(_first_name))
                {
                    std::cout << "First name cannot be empty!" << std::endl;
                    goto labelFN;
                }
                else 
                {
                    contact.set_first_name(_first_name);
                }    
            labelLN:
                std::cout << "Enter last name: ";
                std::getline(std::cin, _last_name);

                if (_last_name == "" || phonebook.ft_all_spaces(_last_name))
                {
                    std::cout << "Last name cannot be empty!" << std::endl;
                    goto labelLN;
                }
                else 
                {
                    contact.set_last_name(_last_name);
                }

            labelNN:
                std::cout << "Enter nickname: ";
                std::getline(std::cin, _nickname);

                if (_nickname == "" || phonebook.ft_all_spaces(_nickname))
                {
                    std::cout << "Nickname cannot be empty!" << std::endl;
                    goto labelNN;
                }
                else 
                {
                    contact.set_nickname(_nickname);
                }

            labelPN:
                std::cout << "Enter phone number: ";
                std::getline(std::cin, _phone_number);

                if (_phone_number == "" || phonebook.ft_all_spaces(_phone_number) || !phonebook.ft_is_number(_phone_number))
                {
                    std::cout << "Phone number cannot be empty or invalid!" << std::endl;
                    goto labelPN;
                }
                else 
                {
                    contact.set_phone_number(_phone_number);
                }
            labelDS:
                std::cout << "Enter darkest secret: ";
                std::getline(std::cin, _darkest_secret);

                if (_darkest_secret == "" || phonebook.ft_all_spaces(_darkest_secret))
                {
                    std::cout << "Darkest secret cannot be empty!" << std::endl;
                    goto labelDS;
                }
                else 
                {
                    contact.set_darkest_secret(_darkest_secret);
                }
                phonebook.ft_add_contact(contact, i);
                
                contact_index++;

                i++;
                
                if (i == 8)
                    i = 0;        
            }
            else if (command == "SEARCH")
            {
                phonebook.ft_print_all_contacts();
                if (contact_index > -1)
                {
                    labelID:
                        std::cout << "Enter the ID of the contact you want to see: ";
                        std::getline(std::cin, command);

                        if (command == "")
                        {
                            std::cout << "ID cannot be empty!" << std::endl;
                            goto labelID;
                        }
                        else if (!phonebook.ft_is_number(command))
                        {
                            std::cout << "ID must be a number!" << std::endl;
                            goto labelID;
                        }
                        else if (!phonebook.ft_is_valid_number(command))
                        {
                            std::cout << "ID must be between 0 and 7!" << std::endl;
                            goto labelID;
                        }
                        else if (contact_index >= std::stoi(command))
                        {
                            phonebook.ft_print_contact(command);
                        }
                        else
                        {
                            std::cout << "Only first " << contact_index + 1 << " contact(s) are available!" << std::endl;
                            goto labelID;
                        }
                }
            }
            else
            {
                std::cout << "Invalid command!" << std::endl;
                std::cout << "Only Available commands: ADD, SEARCH, EXIT" << std::endl;
                goto labelStart;
            }
        }
    return 0;

}