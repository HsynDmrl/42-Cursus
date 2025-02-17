/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:40:42 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 12:38:05 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* zombieHorde(int N, string name) {
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}
