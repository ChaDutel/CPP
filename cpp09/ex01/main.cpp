/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:18:40 by charline          #+#    #+#             */
/*   Updated: 2023/07/05 18:16:36 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR : Wrong number of arguments" << std::endl;
		return (0);
	}
	RPN	rpn;
	try
	{
		rpn.parse(argv[1]);
		for (int i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] == ' ')
				continue;
			else
				rpn.exec(argv[1][i]);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	if (rpn.getNbStack().size() > 1)
		std::cout << "ERROR: Too much numbers left, miss an operator";
	else
		std::cout << rpn.removeNb() << std::endl;
	return (0);
}