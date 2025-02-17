/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:56 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:33:03 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl is born." << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "Harl is dead." << std::endl;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
                    << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I can't believe adding extra bacon cost more. You don't put enough on! If you did, "
                    << "I wouldn't have to ask for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
                    << "I've been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    void (Harl::*options[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if(level == levels[i])
        {
            (this->*options[i])();
            return;
        }
    }

    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
        std::cout << "Invalid level of complaint." << std::endl;

    return;
}
