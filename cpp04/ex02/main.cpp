/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:27 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/05 11:11:53 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// const AAnimal* a = new AAnimal();
	const AAnimal* meta[4];
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const WrongAnimal* w = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	w->makeSound();
	// a->makeSound();
	for (int integer = 0; integer < 4; integer++)
	{
		if (integer % 2 == 0)
			meta[integer] = new Dog();
		else
			meta[integer] = new Cat();
		meta[integer]->makeSound();
	}
	delete j;
	delete i;
	delete w;
	// delete a;
	for (int integer = 0; integer < 4; integer++)
		delete meta[integer];
	return (0);
}
