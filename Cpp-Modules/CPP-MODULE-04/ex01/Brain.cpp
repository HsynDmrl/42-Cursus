/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:38:17 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 16:14:22 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor is called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy) {
    if(this != &copy) 
    {
        for(int i = 0; i < 100; i++)
            _ideas[i] = copy._ideas[i];
    }
    std::cout << "Brain assignation operator is called" << std::endl;
    return *this;
}
