#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <string>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
		MutantStack<T>&	operator=(const MutantStack<T>& other)
		{
			this->c = other.c;
			return (*this);
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator constIterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}

		constIterator	begin() const
		{
			return (this->c.begin());
		}

		constIterator	end() const
		{
			return (this->c.end());
		}
};

# endif
