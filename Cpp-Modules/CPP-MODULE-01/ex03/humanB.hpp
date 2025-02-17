/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:50:15 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:04:44 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "weapon.hpp"

class HumanB
{
    private:
        string _name;
        Weapon* _weapon;
    public:
        HumanB(string name);
        ~HumanB(void);
        void attack(void);
        void setWeapon(Weapon& weapon);
};

#endif