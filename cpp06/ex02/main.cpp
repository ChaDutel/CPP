/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:20:13 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/16 11:14:22 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

void identify(Base& p)
{
	try
	{
		A	a = dynamic_cast<A&>(p);
		std::cout << "The type is 'A'\n";
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

	try
	{
		B	b = dynamic_cast<B&>(p);
		std::cout << "The type is 'B'\n";
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

	try
	{
		C	c = dynamic_cast<C&>(p);
		std::cout << "The type is 'C'\n";
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It's A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It's B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "It's C\n";
}

Base * generate(void)
{
	int	nb;

	std::srand(std::time(0));
	nb = std::rand();
	if (nb % 3 == 0)
		return (new A);
	else if (nb % 3 == 1)
		return (new B);
	else
		return (new C);
}

int	main()
{
	Base	*base;
	
	base = generate();

	identify(base);
	identify(*base);
	delete base;
}

// void identify(Base& p);
// Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". Utiliser un pointeur
// dans cette fonction est interdit.
