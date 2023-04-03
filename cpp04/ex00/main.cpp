/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:37:27 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/03 15:28:35 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int	main()
// {
// 	Animal	animal;
// 	Cat		cat;
// 	Dog		dog;
	
// 	animal.makeSound();
// 	cat.makeSound();
// 	dog.makeSound();
	
// 	return (0);
// }

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
//...
delete j;
delete i;
delete meta;
return 0;
}
