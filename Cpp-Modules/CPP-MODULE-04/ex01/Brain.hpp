/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:38:11 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/20 14:39:01 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
using std::string;

class Brain
{
    private:
        string _ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
};

#endif
