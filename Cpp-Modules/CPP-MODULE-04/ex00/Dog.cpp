/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:42:55 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:26:13 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog is born." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog is dead." << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog copy constructor is called." << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        _type = copy._type;
    std::cout << "Dog assignation operator is called." << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}