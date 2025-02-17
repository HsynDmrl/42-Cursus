/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:37 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:06:06 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
using std::string;

class Contact
{
    private:
        string _first_name, _last_name, _nickname, _phone_number, _darkest_secret;
    public:
        // Constructor
        Contact();
        ~Contact();
        
        // Setter Methods
        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_nickname(string nickname);
        void set_phone_number(string phone_number);
        void set_darkest_secret(string darkest_secret) ;
        
        // Getter Methods
        string get_first_name() const;
        string get_last_name() const;
        string get_nickname() const;
        string get_phone_number() const;
        string get_darkest_secret() const;

};

#endif