/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:41:31 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:24:13 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main() 
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;

    std::cout << "======================" << std::endl;
    
    Animal* animals[6];
    
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "dog: " << i << std::endl;
		animals[i] = new Dog();
	}
	for (int i = 3; i < 6; ++i)
	{
		std::cout << "cat: " << i << std::endl;
		animals[i] = new Cat();
	}
	for (int i = 0; i < 6; ++i)
	{
		std::cout << "destruct: " << i << std::endl;
		delete animals[i];
	}
    return (0);
}