/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:11:30 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/15 17:52:05 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t uptr = reinterpret_cast<uintptr_t>(ptr);
	return (uptr);
}

Data* deserialize(uintptr_t raw)
{
	Data	*draw = reinterpret_cast<Data*>(raw);
	return (draw);
}

int	main()
{
	Data		data;
	uintptr_t	raw;
	Data		*pdata;

	data.i = 42;
	data.str = "Hello World!";
	
	raw = serialize(&data);
	pdata = deserialize(raw);
	
	data.i += 3;
	data.str = "bouh!";

	std::cout << "Data is : " << data.i << " and " << data.str << std::endl;
	std::cout << "Cp Data is : " << pdata->i << " and " << pdata->str << std::endl;

}
