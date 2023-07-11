/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:20:13 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/07/10 17:49:08 by charline         ###   ########.fr       */
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
