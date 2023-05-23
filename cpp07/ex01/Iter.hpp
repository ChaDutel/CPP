#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	ftPrint(T &elem)
{
	std:: cout << elem;
}

template <typename T>
void	iter(T tab[], unsigned int size, void(*ftPrint)(T &elem))
{
	T	*cpTab;

	cpTab = tab;
	std::cout << "Copy tab is: " << cpTab << ", and the original tab is: " << tab << std::endl;
	std:: cout << "The size of the tab is: " << size << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		ftPrint(tab[i]);
	}
	std::cout << std::endl;
}

# endif
