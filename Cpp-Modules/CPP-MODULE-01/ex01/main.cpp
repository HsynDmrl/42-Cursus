/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:39:36 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 13:14:21 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main(void) {
    Zombie* horde = zombieHorde(5, "Zombie");
    for(int i = 0; i < 5; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
