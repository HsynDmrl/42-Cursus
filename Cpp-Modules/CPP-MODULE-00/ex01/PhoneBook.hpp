/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:06:43 by hdemirel          #+#    #+#             */
/*   Updated: 2024/09/20 13:06:48 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
    public:
        PhoneBook();
        ~PhoneBook();
        void ft_add_contact(Contact contact, int index);
        void ft_print_all_contacts();
        void ft_print_contact(const string &str);
        bool ft_is_number(const string &str);
        bool ft_is_valid_number(const string &str);
        bool ft_all_spaces(const string &str);
};

#endif