/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:23:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/14 18:17:43 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	zombie = Zombie("Yvan");
	Zombie*	newZombie = zombie.getNewZombie("Tim");
	
	zombie.randomChump("Max");
	zombie.announce();
	newZombie->announce();
	delete newZombie;
}
