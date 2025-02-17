/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:42:50 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:26:08 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Cat is born." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat is dead." << std::endl;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
    std::cout << "Cat copy constructor is called." << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        _type = copy._type;
    std::cout << "Cat assignation operator is called." << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow" << std::endl;
}