/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:30:38 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/15 11:58:05 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	N = 4;
	Zombie* allZombies = zombieHorde(N, "Boys");
	
	if (N < 1)
		return (0);
	for (int i = 0; i != 4; i++)
		allZombies->announce();
	delete [] allZombies;
	return (0);
}
