/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:42:50 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 15:55:09 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    brain = new Brain();
    std::cout << "Cat is born with a brain." << std::endl;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat is dead without a brain." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    _type = copy._type;
    if (brain)
        delete brain;
    brain = new Brain(*copy.brain);
    std::cout << "Cat copy constructor is called." << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if(this != &copy)
    {
        _type = copy._type;
        if (brain)
            delete brain;
        brain = new Brain(*copy.brain);
    }
    std::cout << "Cat assignation operator is called." << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow" << std::endl;
}