#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int			getRawBits() const;
		void		setRawBits(int const raw);

	private:
		int			_nb;
		const int	_fractional_bits;
};

# endif
