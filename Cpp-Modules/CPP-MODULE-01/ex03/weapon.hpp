/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:42:18 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 13:15:38 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

using std::string;

class Weapon
{
    private:
        string _type;
    public:
        Weapon(string type);
        ~Weapon(void);
        string const getType(void) const;
        void setType(string type);
};

#endif