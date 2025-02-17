/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:43:01 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:18:59 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") 
{
    std::cout << "WrongAnimal is born." << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal is dead." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) 
{
    *this = copy;
    std::cout << "WrongAnimal copy constructor is called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) 
{
    if (this != &copy)
        _type = copy._type;
    std::cout << "WrongAnimal assignation operator is called." << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal makes a sound." << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return _type;
}
