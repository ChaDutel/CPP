/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:18:48 by charline          #+#    #+#             */
/*   Updated: 2023/07/05 18:16:04 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./PmergeMe.hpp"

//----------------------------------------------------------------- EXCEPTIONS -----------------------------------------------------------------//

char const*	TooMuchNbException::what()				const throw() {return ("ERROR: Too much numbers to handle");}
char const*	IntMaxException::what()					const throw() {return ("ERROR: Number is greater than int max");}
char const*	WrongSyntaxException::what()	  		const throw() {return ("ERROR: Wrong syntax");}
// char const*	TooFewNumberException::what()			const throw() {return ("ERROR: Miss a number to execute the operation");}
// char const*	TooFewNumbersException::what()			const throw() {return ("ERROR: Miss a number or more to execute the operation");}
// char const*	TooMuchNumbersException::what()			const throw() {return ("ERROR: Too much numbers");}
// char const*	ZeroDivException::what()				const throw() {return ("ERROR: Cannot divided a number with 0");}


//----------------------------------------------------------------- BUILDERS  -----------------------------------------------------------------//

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

/////////////////////////// GETTERS/SETTERS ///////////////////////////

// std::stack<double> PmergeMe::getNbStack() {return (this->nbStack);}

// void			PmergeMe::addNb(double nb) {this->nbStack.push(nb);}

// double				PmergeMe::removeNb()
// {
// 	double topValue = this->nbStack.top();
// 	this->nbStack.pop();
// 	return (topValue);
// }


/////////////////////////////   UTILS   /////////////////////////////

bool	PmergeMe::isDigit(char c)
{
	if (c > '9' || c < '0')
		return (false);
	return (true);
}


///////////////////////////// EXECUTION /////////////////////////////

// void	PmergeMe::execLi(std::list<int> li)
// {
	
// 	return ;
// }

void	PmergeMe::execVec(std::vector<int> vec)
{
	std::vector<int> mainChain;
  
	// Pairing the elements
	while (!vec.empty())
	{
		int first = vec.front();
		vec.pop_front();
		
		if (!vec.empty())
		{
			int second = vec.front();
			vec.pop_front();
			
			if (first > second)
				std::swap(first, second);
			mainChain.push_back(first);
			mainChain.push_back(second);
		}
		else
			mainChain.push_back(first);
	}


	// Recursive sorting of pairs
	std::vector<int> sortedPairs(mainChain.begin(), mainChain.end());
	std::vector<int> auxPairs;
	
	while (sortedPairs.size() > 1)
	{
		while (!sortedPairs.empty())
		{
			int first = sortedPairs.front();
			sortedPairs.pop_front();
			
			if (!sortedPairs.empty())
			{
				int second = sortedPairs.front();
				sortedPairs.pop_front();
				
				if (first > second)
					std::swap(first, second);
				
				auxPairs.push_back(first);
				auxPairs.push_back(second);
			}
			else
				auxPairs.push_back(first);
		}
		sortedPairs.swap(auxPairs);
	}
	
	mainChain.swap(sortedPairs);
	
	// Insertion of remaining elements
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::vector<int>::iterator insertionPos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
		mainChain.insert(insertionPos, *it);
	}
	
	// Print final sorted list
	for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return ;
}


/////////////////////////////  PARSING  /////////////////////////////

void	PmergeMe::parse(std::string str)
{
	// max number
	if (str.size() > 10000)
		throw TooMuchNbException();
	double	max;
	for (int i = 0; str[i]; i++)
	{
		if (isDigit(str[i]) == false)
			throw WrongSyntaxException();
		max += std::atoi(&str[i]);
		if (max > INT_MAX)
			throw IntMaxException();
	}