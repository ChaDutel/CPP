/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:12:25 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/25 15:36:52 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "The size of mstack after 'pop' is " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;

	MutantStack<std::string> mstring;
    mstring.push("Hello");
    mstring.push("world!");
    std::cout << "The size of mstring before 'pop' is " << mstring.size() << std::endl;
    std::cout << mstring.top() << std::endl;
    mstring.pop();
    std::cout << "The size of mstring after 'pop' is " << mstring.size() << std::endl;
    mstring.push("you!");
    mstring.push("Welcome");
    mstring.push("and be");
    mstring.push("happy and live");
    mstring.push("with peace <3");
    MutantStack<std::string>::iterator itt = mstring.begin();
    MutantStack<std::string>::iterator itte = mstring.end();
    ++itt;
    --itt;
	std::cout << std::endl;
    while (itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    std::stack<std::string> ss(mstring);
	return (0);
}
