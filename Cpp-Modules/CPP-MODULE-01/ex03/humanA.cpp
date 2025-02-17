/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:41 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:04:28 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << _name << " is born." << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << _name << " is dead." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}