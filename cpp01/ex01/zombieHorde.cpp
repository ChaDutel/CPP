/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:24:10 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/15 11:57:27 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	newZombies = new Zombie[N]();

	if (N < 1)
		return (NULL);
	for (int i = 0; i != N; i++)
		newZombies[i].setName(name);
	return (newZombies);
}
