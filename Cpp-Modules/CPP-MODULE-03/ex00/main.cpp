/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:38:55 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 16:36:31 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("a");
    ClapTrap b("b");
    ClapTrap c(b);

    b.attack("a");
    a.takeDamage(5);
    a.beRepaired(10);
    return 0;
}