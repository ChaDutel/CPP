/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:40:51 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/23 12:01:28 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Iter.hpp"

int main( void )
{
	char			tab[] = "Hello World!";
	unsigned int	size = 13;
	int				intTab[] = {4, 8, 6};
	unsigned int	intSize = 3;
	
	iter(tab, size, &ftPrint);
	iter(intTab, intSize, &ftPrint);
	return 0;
}
