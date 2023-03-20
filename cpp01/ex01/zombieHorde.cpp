/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:24:10 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 11:56:14 by charline         ###   ########.fr       */
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
