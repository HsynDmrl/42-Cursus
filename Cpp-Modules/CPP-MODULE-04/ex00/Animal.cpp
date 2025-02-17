/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:42:46 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:26:22 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") 
{
    std::cout << "Animal is born." << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal is dead." << std::endl;
}

Animal::Animal(const Animal &copy) 
{
    *this = copy;
    std::cout << "Animal copy constructor is called." << std::endl;
}

Animal &Animal::operator=(const Animal &copy) 
{
    if (this != &copy)
        _type = copy._type;
    std::cout << "Animal assignation operator is called." << std::endl;
    return *this;
}

void Animal::makeSound() const 
{
    std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const 
{
    return _type;
}
