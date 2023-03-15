/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:23:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/15 11:31:10 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	zombie = Zombie("Yvan");
	Zombie*	aNewZombie = newZombie("Tim");
	
	zombie.announce();
	aNewZombie->announce();
	randomChump("Max");
	delete aNewZombie;
	return (0);
}
