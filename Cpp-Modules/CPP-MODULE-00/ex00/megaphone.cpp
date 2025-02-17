/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:20:21 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:18:24 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
     else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            for (size_t j = 0; j < arg.length(); j++)
            {
                std::cout << (char)toupper(arg[j]);
            }
        }
    }
    std::cout << std::endl;
    return 0;
}