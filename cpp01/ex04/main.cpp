/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 12:38:04 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of parameters\n";
		return (0);
	}
	manageFiles(argv);
}
