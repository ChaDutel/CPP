#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
class Array
{
	public:
		Array()
		{
			_array = NULL;
			_size = 0;
		}

		Array(unsigned int n) : _size(n)
		{
			if (_size == 0)
				_array = NULL;
			else
			{
				_array = new T[_size];
				
				for (int i = 0; _array[i]; i++)
					_array[i] = T();
			}
		}

		Array(const Array &src)
		{
			this->_size = src._size;
			// this->_array = src._array;
			if (_size != 0)
			{
				this->_array = new T(_size);
				for (int i = 0; _array[i]; i++)
					this->_array[i] = src._array[i];
			}
		}

		Array	&operator=(const Array &src)
		{
			this->_size = src._size;
			_array = new T[_size];

			for (int i = 0; _array[i]; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}

		T	&operator[](unsigned int i)
		{
			if (i >= _size)
				throw (std::out_of_range("Error: index is out of range"));
			else
				return(_array[i]);
		}

		T	const &operator[](unsigned int i) const
		{
			if (i >= _size)
				throw (std::out_of_range("Error: index is out of range"));
			else
				return(_array[i]);
		}

		~Array()
		{
			delete	_array;
		}

		unsigned int size()
		{
			return (_size);
		}

	private:
		T				*_array;
		unsigned int	_size;
};

# endif
