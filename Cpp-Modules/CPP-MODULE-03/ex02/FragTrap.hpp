/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:05:55 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/19 17:34:54 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
using std::string;

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();
        FragTrap &operator=(FragTrap const &copy);

        void attack(string const &target);
        void highFivesGuys(void);
};

#endif