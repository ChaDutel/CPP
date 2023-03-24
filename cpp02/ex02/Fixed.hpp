#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatNb);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&	operator=(const Fixed& other);

		// Comparaison //
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator==(const Fixed& other);
		bool	operator!=(const Fixed& other);

		// Arithemtics //
		Fixed		operator+(const Fixed& other);
		Fixed		operator-(const Fixed& other);
		Fixed		operator*(const Fixed& other);
		Fixed		operator/(const Fixed& other);

		Fixed&		min(Fixed&	fixOne, Fixed& fixTwo);
		Fixed&		max(Fixed& fixOne, Fixed& fixTwo);
		Fixed&		min(Fixed& const fixOne, Fixed& const fixTwo) const;
		Fixed&		max(Fixed& const fixOne, Fixed& const fixTwo) const;
		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

	private:
		int			_nb;
		const int	_fractional_bits;
};

std::ostream& operator<<(std::ostream &out, const Fixed& other);

# endif
