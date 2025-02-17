/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:43:45 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:03:20 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"
#include "weapon.hpp"

Weapon::Weapon(string type) : _type(type)
{
    std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon destroyed" << std::endl;
}

string const Weapon::getType(void) const
{
    return _type;
}

void Weapon::setType(string type)
{
    _type = type;
}
