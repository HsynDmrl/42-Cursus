/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:43:05 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:19:45 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "WrongCat is born." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat is dead." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "WrongCat copy constructor is called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        _type = copy._type;
    std::cout << "WrongCat assignation operator is called." << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: Meow Meow" << std::endl;
}
