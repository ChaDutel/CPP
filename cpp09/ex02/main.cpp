/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:18:40 by charline          #+#    #+#             */
/*   Updated: 2023/07/18 17:58:47 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

bool	checkIsSortedVect(std::vector<int> vec)
{
	std::vector<int>::iterator	itPrev = vec.begin();
	std::vector<int>::iterator	itNext = vec.begin() + 1;
	while (itPrev != vec.end() && itNext != vec.end())
	{
		if (*itPrev > *itNext)
			break ;
		itPrev++;
		itNext++;
	}
	if (itNext == vec.end())
	{
		std::cout << "Before: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << "\nAfter:  ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 10000)
	{
		std::cout << "ERROR : Wrong number of arguments" << std::endl;
		return (0);
	}
	PmergeMe	pmergeMe;
	try
	{
		for (int i = 1; argv[i]; i++)
			pmergeMe.parse(argv[i]);
		std::list<int>		li;
		std::vector<int>	vec;
		for (int i = 1; argv[i]; i++)
		{
			li.push_back(std::atoi(argv[i]));
			vec.push_back(std::atoi(argv[i]));
		}
		if (checkIsSortedVect(vec) == true)
		{
			std:: cout << "Time to process a range of " << vec.size() << " elements with std::vector : 0.0 us" << std::endl;
			std:: cout << "Time to process a range of " << li.size() << " elements with std::list   : 0.0 us" << std::endl;
			return (0);
		}
		std::cout << "Before: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::clock_t cStartVec = std::clock();
		std::vector<int>	sortedVec = pmergeMe.execVec(vec);
		std::clock_t cEndVec = std::clock();
		std::clock_t cStartLi = std::clock();
		pmergeMe.execLi(li);
		std::clock_t cEndLi = std::clock();
		double runtimeVec = static_cast<double>(cEndVec - cStartVec) / (CLOCKS_PER_SEC / 1000000);
		double runtimeLi = static_cast<double>(cEndLi - cStartLi) / (CLOCKS_PER_SEC / 1000000);
		std::cout << "After:  ";
		for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std:: cout << "Time to process a range of " << vec.size() << " elements with std::vector : " <<  runtimeVec << " us" << std::endl;
		std:: cout << "Time to process a range of " << li.size() << " elements with std::list   : " << runtimeLi << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (0);
}
