/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:15:38 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 13:13:51 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main(void) {
    Zombie* zombie = newZombie("Foo");
    zombie->announce();
    delete zombie;

    randomChump("Zoo");
    return 0;
}
