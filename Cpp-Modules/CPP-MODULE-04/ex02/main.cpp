/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:41:31 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:39:14 by hdemirel         ###   ########.fr       */
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
    
	Animal *a = new Dog(); 
	a->makeSound();
	delete a;
	
	// it is not possible to create an instance of an abstract class
	//Animal *b = new Animal(); 
	//b->makeSound();

    return (0);
}