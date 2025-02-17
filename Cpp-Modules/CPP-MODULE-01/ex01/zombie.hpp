/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:40:14 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 17:50:53 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::string;

class Zombie {
    private:
        string _name;
    public:
        Zombie(void);
        Zombie(string name);
        ~Zombie(void);
        void announce(void);
        void setName(string name);
};

Zombie* zombieHorde(int N, string name);

#endif
