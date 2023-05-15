/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:28:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/15 12:22:57 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Convert.hpp"

int    main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std:: endl;	
		return (0);
	}
	int		identifiedType;
	Convert		str;
	// Convert		sstr(argv[1]);
	
	identifiedType = str.findType(argv[1]);
	// identifiedType = sstr.findType(sstr.getStr());

	str.printGoodType(identifiedType, argv[1]);
	// sstr.printGoodType(identifiedType, sstr.getStr());
	return (0);
}
