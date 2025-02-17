/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:57:47 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:38:51 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return 1;
    }
    else
    {
        Harl harl;
        harl.complain(argv[1]);
        
    }
    return 0;
}