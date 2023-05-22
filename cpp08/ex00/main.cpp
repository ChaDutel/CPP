/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:54:52 by charline          #+#    #+#             */
/*   Updated: 2023/05/22 20:50:19 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main()
{
	std::vector<int>    vec;

	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(15);
	vec.push_back(51);
	
	std::deque<int>     deq;
	
	deq.push_back(7);
	deq.push_back(5);
	deq.push_back(51);

	int	i = 15;
	if (easyfind(vec, i) == true)
		std::cout << "Success : Vec could find " << i << std::endl;
	else
		std::cout << "Error : Vec cannot find " << i << std::endl;
		
	if (easyfind(deq, i) == true)
		std::cout << "Success : Deq could find " << i << std::endl;
	else
		std::cout << "Error : Deq cannot find " << i << std::endl;
}