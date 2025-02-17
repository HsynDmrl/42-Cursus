/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:16:07 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 12:47:30 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(string name) : _name(name) {
    std::cout << "Zombie " << _name << " is born." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << _name << " is dead." << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
