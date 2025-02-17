/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:35:34 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 13:14:41 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::string;

int main(void)
{
    string str = "HI THIS IS BRAIN";
    string *stringPtr = &str;
    string &stringRef = str;

    std::cout << "String: " << &str << std::endl;
    std::cout << "Pointer: " << stringPtr << std::endl;
    std::cout << "Reference: " << &stringRef << std::endl << std::endl;

    std::cout << "String: " << str << std::endl;
    std::cout << "Pointer: " << *stringPtr << std::endl;
    std::cout << "Reference: " << stringRef << std::endl;
    
    return 0;
}
