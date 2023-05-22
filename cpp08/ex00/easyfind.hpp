#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>

template <typename T>
bool	easyfind(T contInt, int nbToFind)
{
	typename	T::iterator it = std::find(contInt.begin(), contInt.end(), nbToFind);

	if (it != contInt.end())
		return (true);
	else
		return (false);
	return (true);
}

# endif