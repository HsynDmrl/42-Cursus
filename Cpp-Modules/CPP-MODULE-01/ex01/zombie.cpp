/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:40:39 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 12:52:12 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "A zombie is born." << std::endl;
}

Zombie::Zombie(string name) : _name(name)
{
    std::cout << _name << " is born." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " is dead." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(string name) 
{
    _name = name;
}

