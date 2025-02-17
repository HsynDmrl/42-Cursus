/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:11 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 16:37:12 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _health(10), _energy(10), _damage(0)
{
    std::cout << "Default constructor " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(string name) : _name(name), _health(10), _energy(10), _damage(0)
{
    std::cout << "ClapTrap constructor " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) 
{
    *this = copy;
    std::cout << "ClapTrap copy constructor " << copy._name << " is called." << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap has been destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) 
{
    _name = copy._name;
    _health = copy._health;
    _energy = copy._energy;
    _damage = copy._damage;
    std::cout << "ClapTrap assignment operator " << copy._name << " is called." << std::endl;
    return *this;
}

void ClapTrap::attack(string const &target) 
{
    if (_health == 0)
    {
        std::cout << _name << " is already dead." << std::endl;
        return;
    }
    else if (_energy == 0)
    {
        std::cout << _name << " has no energy to attack." << std::endl;
        return;
    }
    _energy--;
    std::cout << _name << " attacks " << target << ", causing [" << _damage << "] points of damage!" << std::endl;
    std::cout << _name << " has [" << _energy << "] energy points left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_health == 0)
    {
        std::cout << _name << " is already dead." << std::endl;
        return;
    }
    _health -= amount;
    if (_health > 0)
    {
        std::cout << _name << " takes [" << amount << "] points of damage!" << std::endl;
        std::cout << _name << " has [" << _health << "] health points left." << std::endl;
    }
    else
    {
        std::cout << _name << " takes [" << amount << "] points of damage!" << std::endl;
        std::cout << _name << " has [" << _health << "] health points left." << std::endl;
        std::cout << _name << " is dead." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (_health == 0)
    {
        std::cout << _name << " is already dead." << std::endl;
        return;
    }
    else if (_energy == 0)
    {
        std::cout << _name << " has no energy to repair." << std::endl;
        return;
    }
    _health += amount;
    _energy--;
    std::cout << _name << " has been repaired for [" << amount << "] points!" << std::endl;
}

string ClapTrap::getName() const
{
    return _name;
}

int ClapTrap::getHealth() const
{
    return _health;
}

int ClapTrap::getEnergy() const
{
    return _energy;
}

