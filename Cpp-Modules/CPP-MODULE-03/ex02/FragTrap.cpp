/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:06:08 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 17:35:40 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
    _health = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "Child FragTrap Default constructor " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name)
{
    _health = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "Child FragTrap constructor " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    *this = copy;
    std::cout << "Child FragTrap copy constructor " << copy._name << " is called." << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << "Child FragTrap has been destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) 
{
    _name = copy._name;
    _health = copy._health;
    _energy = copy._energy;
    _damage = copy._damage;
    std::cout << "Child FragTrap assignment operator " << copy._name << " is called." << std::endl;
    return *this;
}

void FragTrap::attack(string const &target)
{
    if (_health == 0)
    {
        std::cout << "Child FragTrap" << _name << " is already dead." << std::endl;
        return;
    }
    else if (_energy == 0)
    {
        std::cout << "Child FragTrap" << _name << " is out of energy." << std::endl;
        return;
    }
    _energy -= 10;
    std::cout << "Child FragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Child FragTrap " << _name << " high fives guys!" << std::endl;
}