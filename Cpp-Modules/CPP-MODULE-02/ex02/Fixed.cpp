/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:01:03 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/17 19:33:15 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &number) {
    if(this != &number)
        _value = number.getRawBits();
    return *this;
}

Fixed::Fixed(const int intValue) {
    _value = intValue << _bits;
}

Fixed::Fixed(const float floatValue) {
    _value = roundf(floatValue * (1 << _bits));
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _bits);
}

int Fixed::toInt(void) const {
    return _value >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &number) {
    out << number.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &number) const {
    return Fixed(toFloat() + number.toFloat());
}

Fixed Fixed::operator-(const Fixed &number) const {
    return Fixed(toFloat() - number.toFloat());
}

Fixed Fixed::operator*(const Fixed &number) const {
    return Fixed(toFloat() * number.toFloat());
}

Fixed Fixed::operator/(const Fixed &number) const {
    return Fixed(toFloat() / number.toFloat());
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed &Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}

Fixed &Fixed::operator--() {
    _value--;
    return *this;
}

bool Fixed::operator>(const Fixed &number) const {
    return toFloat() > number.toFloat();
}

bool Fixed::operator<(const Fixed &number) const {
    return toFloat() < number.toFloat();
}

bool Fixed::operator>=(const Fixed &number) const {
    return toFloat() >= number.toFloat();
}

bool Fixed::operator<=(const Fixed &number) const {
    return toFloat() <= number.toFloat();
}

bool Fixed::operator==(const Fixed &number) const {
    return toFloat() == number.toFloat();
}

bool Fixed::operator!=(const Fixed &number) const {
    return toFloat() != number.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}
