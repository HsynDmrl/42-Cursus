/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:38:55 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 17:01:24 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a;
    ClapTrap b("b");
    ScavTrap c = a;
    
    b.attack("a");
    a.takeDamage(5);
    a.beRepaired(10);
    return 0;
}