/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:25:09 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/24 18:01:14 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// Builder ///

Fixed::Fixed() : _nb(0), _fractional_bits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integer) : _fractional_bits(8)
{
	std::cout << "Default constructor called" << std::endl;

	_nb = integer << _fractional_bits;
}

Fixed::Fixed(float floatNb) : _fractional_bits(8)
{
	std::cout << "Default constructor called" << std::endl;
	_nb = roundf(floatNb * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& other) : _nb(other._nb), _fractional_bits(other._fractional_bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/// Operator ///

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = other._nb;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

// Arithemtics //

Fixed Fixed::operator+(const Fixed& other)
{
	return (Fixed (this->_nb + other.getRawBits()));
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (Fixed (this->_nb - other.getRawBits()));
}

Fixed Fixed::operator*(const Fixed& other)
{
	return (Fixed (this->_nb * other.getRawBits()));
}

Fixed Fixed::operator/(const Fixed& other)
{
	return (Fixed (this->_nb / other.getRawBits()));
}

// Comparaison //

bool Fixed::operator>(const Fixed& other)
{
	return (this->_nb > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other)
{
	return (this->_nb < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other)
{
	return (this->_nb >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other)
{
	return (this->_nb <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other)
{
	return (this->_nb == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other)
{
	return (this->_nb != other.getRawBits());
}

Fixed&		min(Fixed&	fixOne, Fixed& fixTwo)
{
	if (fixOne < fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}

Fixed&		max(Fixed& fixOne, Fixed& fixTwo)
{
	if (fixOne > fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}

Fixed&		min(Fixed& const fixOne, Fixed& const fixTwo) const
{
	if (fixOne < fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}
Fixed&		max(Fixed& const fixOne, Fixed& const fixTwo) const
{
	if (fixOne > fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}


/// Function ///

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

float		Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << _fractional_bits));
}

int			Fixed::toInt(void) const
{
	return (this->_nb >> _fractional_bits);
}
