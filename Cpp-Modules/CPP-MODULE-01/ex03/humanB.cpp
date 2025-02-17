/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:20:58 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 12:52:33 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    std::cout << "HumanB " << _name << " is born." << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << _name << " is dead." << std::endl;
}

void HumanB::attack()
{
    if (_weapon)
    {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    }
    else
    {
        std::cout << _name << " attacks with their bare hands" << std::endl;
    }
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}
