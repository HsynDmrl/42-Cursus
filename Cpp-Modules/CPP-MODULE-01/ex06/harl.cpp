/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:48 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:36:22 by hdemirel         ###   ########.fr       */
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
    std::cout << "I can't believe adding extra bacon cost more. You don't put enough on! If you did, " << std::endl
                    << "I wouldn't have to ask for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. " << std::endl
                    << "I've been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i;
    for(i = 0; i < 4; i++)
    {
        if(level == levels[i])
            break;
    }
    
    switch (i)
    {
        case 0:
            std::cout << "[ DEBUG ] " << std::endl;
            debug();
            std::cout << std::endl;
            std::cout << " [ INFO ] " << std::endl;
            info();
            std::cout << std::endl;
            std::cout << " [ WARNING ] " << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << " [ ERROR ] " << std::endl;
            error();
            break;
        case 1:
            std::cout << " [ INFO ] " << std::endl;
            info();
            std::cout << std::endl;
            std::cout << " [ WARNING ] " << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << " [ ERROR ] " << std::endl;
            error();
            break;
        case 2:
            std::cout << " [ WARNING ] " << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << " [ ERROR ] " << std::endl;
            error();
            break;
        case 3:
            std::cout << " [ ERROR ] " << std::endl;
            error();
            break;
        default:
            std::cout << "Invalid level of complaint." << std::endl;
            break;
    }
}