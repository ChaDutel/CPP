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
		Fixed&	operator=(const Fixed& other);
		~Fixed();

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
