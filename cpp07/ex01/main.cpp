/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:40:51 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/17 13:51:25 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Iter.hpp"

int main( void )
{
	char			tab[] = "Hello World!";
	unsigned int	size = 13;
	
	iter(tab, size, &ftPrint);
	return 0;
}
