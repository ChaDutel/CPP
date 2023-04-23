/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:27 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 17:40:19 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* 		meta[4];
	const Animal* 		j = new Dog();
	const Animal* 		i = new Cat();
	const WrongAnimal* 	w = new WrongCat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	w->makeSound();
	std::cout << std::endl;
	for (int integer = 0; integer < 4; integer++)
	{
		if (integer % 2 == 0)
			meta[integer] = new Dog();
		else
			meta[integer] = new Cat();
		meta[integer]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	delete w;
	std::cout << std::endl << std::endl << std::endl;
	for (int integer = 0; integer < 4; integer++)
	{
		delete meta[integer];
		std::cout << std::endl;
	}

	std::cout << "------------ No Const -------------" << std::endl;

	Dog	doggy;
	Dog hotdog(doggy);

	doggy.learn("Jump");
	
	std::cout << std::endl;
	std::cout << doggy.getLearn(0) << std::endl;
	std::cout << doggy.getLearn(1) << std::endl;
	
	std::cout << hotdog.getLearn(0) << std::endl;
	hotdog = doggy;
	std::cout << hotdog.getLearn(0) << std::endl;
	std::cout << std::endl;
	

	return (0);
}
