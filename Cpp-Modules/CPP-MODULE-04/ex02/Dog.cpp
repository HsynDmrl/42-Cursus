/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:42:55 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:10:56 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    brain = new Brain();
    std::cout << "Dog is born with a brain." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog is dead without a brain." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    _type = copy._type;
    if (brain)
        delete brain;
    brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor is called." << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if(this != &copy)
    {
        _type = copy._type;
        if (brain)
            delete brain;
        brain = new Brain(*copy.brain);
    }
    std::cout << "Dog assignation operator is called." << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}