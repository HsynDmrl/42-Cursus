/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:01:05 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/17 19:33:39 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &copy);
        ~Fixed(void);
        Fixed &operator=(const Fixed &number);
        Fixed(const int intValue);
        Fixed(const float floatValue);

        Fixed operator+(const Fixed &number) const;
        Fixed operator-(const Fixed &number) const;
        Fixed operator*(const Fixed &number) const;
        Fixed operator/(const Fixed &number) const;

        Fixed operator++(int);
        Fixed &operator++();
        Fixed operator--(int);
        Fixed &operator--();

        bool operator>(const Fixed &number) const;
        bool operator<(const Fixed &number) const;
        bool operator>=(const Fixed &number) const;
        bool operator<=(const Fixed &number) const;
        bool operator==(const Fixed &number) const;
        bool operator!=(const Fixed &number) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);

        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};
        
std::ostream &operator<<(std::ostream &out, const Fixed &number);

#endif