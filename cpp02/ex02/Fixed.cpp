/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:25:09 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/25 12:46:22 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// Builder ///

Fixed::Fixed() : _nb(0), _fractional_bits(8)
{
}

Fixed::Fixed(int integer) : _fractional_bits(8)
{
	_nb = integer << _fractional_bits;
}

Fixed::Fixed(float floatNb) : _fractional_bits(8)
{
	_nb = roundf(floatNb * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& other) : _nb(other._nb), _fractional_bits(other._fractional_bits)
{
}

Fixed::~Fixed()
{
}



/// Operator ///

Fixed& Fixed::operator=(const Fixed& other)
{
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
	Fixed tmp;
	long long	firstVariable;
	long long	secondVariable;

	firstVariable = (long long)this->getRawBits();
	secondVariable = (long long)other.getRawBits();
	tmp.setRawBits((firstVariable * secondVariable) / (1 << _fractional_bits));
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed		tmp;
	long long	firstVariable;
	long long	secondVariable;

	firstVariable = (long long)this->getRawBits();
	secondVariable = (long long)other.getRawBits();
	tmp.setRawBits((firstVariable * (1 << _fractional_bits)) / secondVariable);
	return (tmp);
}

	// Incrementation //

Fixed	Fixed::operator++()
{
	this->_nb++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;
	
	tmp._nb = _nb;
	this->_nb++;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_nb--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;
	
	tmp._nb = _nb;
	this->_nb--;
	return (tmp);
}

	// Comparaison //

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_nb > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
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

	// Max and Min //

Fixed&	Fixed::min(Fixed&	fixOne, Fixed& fixTwo)
{
	if (fixOne < fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}

Fixed&	Fixed::max(Fixed& fixOne, Fixed& fixTwo)
{
	if (fixOne > fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}

Fixed const	&Fixed::min(const Fixed& fixOne, const Fixed& fixTwo)
{
	if (fixOne < fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}

Fixed const	&Fixed::max(const Fixed& fixOne, const Fixed& fixTwo)
{
	if (fixOne > fixTwo)
		return (fixOne);
	else
		return (fixTwo);
}



/// Function ///

int Fixed::getRawBits() const
{
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
