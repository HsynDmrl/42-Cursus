/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:45:49 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/08 18:04:19 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "weapon.hpp"

class HumanA
{
    private:
        string _name;
        Weapon& _weapon;
    public:
        HumanA(string name, Weapon& weapon);
        ~HumanA(void);
        void attack(void);
};

#endif