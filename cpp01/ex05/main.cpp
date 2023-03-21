/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:52:03 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/21 12:16:46 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	harll;
	
	harll.complain("ERROR");
	harll.complain("WARNING");
	harll.complain("DEBUG");
	harll.complain("INFO");
	
	harll.complain("");
	return (0);
}
