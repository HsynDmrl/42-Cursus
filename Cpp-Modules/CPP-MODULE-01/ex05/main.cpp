/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:54 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 15:51:33 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(void)
{
    Harl harl;

    string level;
    std::cout << "Enter the level of complaint: (DEBUG, INFO, WARNING, ERROR)" << std::endl;
    std::cin >> level;
    
    harl.complain(level);
    return 0;
}