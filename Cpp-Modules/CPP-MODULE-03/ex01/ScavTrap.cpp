/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:43:32 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 16:59:08 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    _health = 100;
    _energy = 50;
    _damage = 20;
    std::cout << "Child ScavTrap Default constructor " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
    _health = 100;
    _energy = 50;
    _damage = 20;
    std::cout << "Child ScavTrap constructor " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    *this = copy;
    std::cout << "Child ScavTrap copy constructor " << copy._name << " is called." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Child ScavTrap " << _name << " has been destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
    _name = copy._name;
    _health = copy._health;
    _energy = copy._energy;
    _damage = copy._damage;
    std::cout << "Child ScavTrap assignment operator " << copy._name << " is called." << std::endl;
    return *this;
}

void ScavTrap::attack(string const &target)
{
    if (_health == 0)
    {
        std::cout << "Child " << _name << " is already dead." << std::endl;
        return;
    }
    else if (_energy == 0)
    {
        std::cout << "Child " << _name << " has no energy to attack." << std::endl;
        return;
    }
    _energy--;
    std::cout << "Child " << _name << " attacks " << target << ", causing [" << _damage << "] points of damage!" << std::endl;
    std::cout << "Child " << _name << " has [" << _energy << "] energy points left." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}
