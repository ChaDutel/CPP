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

		int					getRawBits() const;
		void				setRawBits(int const raw);

	private:
		int					_nb;
		const int	_fractional_bits;
};

/* #include <iostream>

class	Fixed
{
	public :
		Fixed();
		Fixed(int const n);
		Fixed(Fixed const & src);
		~Fixed();

		int getRawBits() const;
		// Fixed& operator(Fixed const & rhs);
	private :
		int	_nb;
};

// std::ostream & operator<<(std::ostream  & o, Fixed const & i); */

/*
#include <iostream>

class Fixed {
private:
    int value;
    static const int fractional_bits = 8;

public:
    Fixed() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed(const Fixed& other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Fixed& operator=(const Fixed& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        value = other.value;
        return *this;
    }

    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

    int getRawBits() const {
        std::cout << "getRawBits member function called" << std::endl;
        return value;
    }

    void setRawBits(int const raw) {
        value = raw;
    }
};

*/

# endif
