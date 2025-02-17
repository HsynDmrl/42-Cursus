/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:35 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:01:13 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(string first_name)
{
    _first_name = first_name;
    std::cout << "First name successfully set to " << first_name << "." << std::endl;
}

void Contact::set_last_name(string last_name)
{
    _last_name = last_name;
    std::cout << "Last Name successfully set to " << last_name << "." << std::endl;
}

void Contact::set_nickname(string nickname)
{
    _nickname = nickname;
    std::cout << "Nickname successfully set to " << nickname << "." << std::endl;
}

void Contact::set_phone_number(string phone_number)
{
    _phone_number = phone_number;
    std::cout << "Phone Number successfully set to " << phone_number << "." << std::endl;
}

void Contact::set_darkest_secret(string darkest_secret)
{
    _darkest_secret = darkest_secret;
    std::cout << "Darkest Secret successfully set to " << darkest_secret << "." << std::endl;
}

string Contact::get_first_name() const
{
    return (_first_name);
}

string Contact::get_last_name() const
{
    return (_last_name);
}

string Contact::get_nickname() const
{
    return (_nickname);
}

string Contact::get_phone_number() const
{
    return (_phone_number);
}

string Contact::get_darkest_secret() const
{
    return(_darkest_secret);
}

Contact::Contact(){}

Contact::~Contact(){}