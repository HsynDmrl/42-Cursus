/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:22:05 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 12:47:36 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
using std::string;

class Zombie
{
    private:
        string _name;
    public:
        Zombie(string name);
        ~Zombie(void);
        void announce(void);
};

Zombie* newZombie(string name);
void randomChump(string name);

#endif