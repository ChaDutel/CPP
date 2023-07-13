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

int binarySearch(std::vector<int> vec, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

	// If the element is present at the middle
	// itself
	if (vec[mid] == x)
		return mid;
	else if (r - l == -1)
		return (r);
	// If element is smaller than mid, then
	// it can only be present in left subarray
	else if (vec[mid] > x)
		return binarySearch(vec, l, mid - 1, x);

	// Else the element can only be present
	// in right subarray
	return binarySearch(vec, mid + 1, r, x);
}

void addElemVect(std::vector<int> &chain, int value)
{
	std::vector<int>::iterator	it = chain.begin();
	if (chain.empty())
		chain.push_back(value);
	else
	{
		if (value >= chain.back())
		{
			chain.push_back(value);
		}
		else if (value <= chain.front())
			chain.insert(it, value);
		else
		{
			int	index = binarySearch(chain, 0, chain.size() - 1, value);
			chain.insert(it + index, value);
		}
	}
}

// void	PmergeMe::execLi(std::list<int> li)
// {
	
// 	return ;
// }

void	PmergeMe::execVec(std::vector<int> vec)
{
	std::vector<int> chainSmaller;
	std::vector<int> chainGreater;
  
	// int		lValue;
	// bool	odd = false;
	// if (vec.size() % 2 != 0)
	// {
	// 	lValue = vec.back();
	// 	vec.pop_back();
	// 	odd = true;
	// }
	// Pairing the elements
	std::cout << "Before: ";
	while (!vec.empty())
	{
		std::vector<int>::iterator it = vec.begin();
		int first = vec.front();
		vec.erase(it);
		std::cout << first << " ";
		// vec.pop_front();
		
		if (!vec.empty())
		{
			it = vec.begin();
			int second = vec.front();
			vec.erase(it);
			std::cout << second << " ";
			// vec.pop_front();
			
			if (first > second)
			{
				// addElemVect(chainGreater, first);
				chainGreater.push_back(first);
				addElemVect(chainSmaller, second);
				// it = chainGreater.begin();
				// if (chainGreater.empty())
				// 	chainGreater.push_back(first);
				// else
				// {
				// 	if (first >= chainGreater.back())
				// 		chainGreater.push_back(first);
				// 	else if (first <= chainGreater.front())
				// 		chainGreater.insert(it, first);
				// 	int	index = binarySearch(chainGreater, 0, chainGreater.size() - 1, first);
				// 	chainGreater.insert(it + index, first);
				// }
					// int binarySearch(int arr[], int l, int r, int x)

			}
			else
			{
				// addElemVect(chainGreater, second);
				chainGreater.push_back(second);
				addElemVect(chainSmaller, first);
			}
			// if (first > second)
			// 	std::swap(first, second);
			// mainChainPairSort.push_back(first);
			// mainChainPairSort.push_back(second);
		}
		else
			addElemVect(chainSmaller, first);
			// mainChainPairSort.push_back(first);
	}
	// construct mainChain
	while (!chainGreater.empty())
	{
		std::vector<int>::iterator it = chainGreater.begin();
		int first = chainGreater.front();
		chainGreater.erase(it);
		addElemVect(chainSmaller, first);
	}
	// if (odd == true)
	// 	addElemVect(chainSmaller, lValue);
	std::cout << "\nAfter: ";
	for (std::vector<int>::iterator it = chainSmaller.begin(); it != chainSmaller.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;








	// // Recursive sorting of pairs
	// std::vector<int> sortedPairs(mainChainPairSort.begin(), mainChainPairSort.end());
	// std::vector<int> auxPairs;
	
	// while (sortedPairs.size() > 1)
	// {
	// 	while (!sortedPairs.empty())
	// 	{
	// 		int first = sortedPairs.front();
	// 		sortedPairs.pop_front();
			
	// 		if (!sortedPairs.empty())
	// 		{
	// 			int second = sortedPairs.front();
	// 			sortedPairs.pop_front();
				
	// 			if (first > second)
	// 				std::swap(first, second);
				
	// 			auxPairs.push_back(first);
	// 			auxPairs.push_back(second);
	// 		}
	// 		else
	// 			auxPairs.push_back(first);
	// 	}
	// 	sortedPairs.swap(auxPairs);
	// }
	
	// mainChainPairSort.swap(sortedPairs);
	
	// // Insertion of remaining elements
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	// {
	// 	std::vector<int>::iterator insertionPos = std::lower_bound(mainChainPairSort.begin(), mainChainPairSort.end(), *it);
	// 	mainChainPairSort.insert(insertionPos, *it);
	// }
	return ;
}

// void	PmergeMe::execVec(std::vector<int> vec)
// {
// 	std::vector<int> mainChain;
  
// 	// Pairing the elements
// 	while (!vec.empty())
// 	{
// 		int first = vec.front();
// 		vec.pop_front();
		
// 		if (!vec.empty())
// 		{
// 			int second = vec.front();
// 			vec.pop_front();
			
// 			if (first > second)
// 				std::swap(first, second);
// 			mainChain.push_back(first);
// 			mainChain.push_back(second);
// 		}
// 		else
// 			mainChain.push_back(first);
// 	}


// 	// Recursive sorting of pairs
// 	std::vector<int> sortedPairs(mainChain.begin(), mainChain.end());
// 	std::vector<int> auxPairs;
	
// 	while (sortedPairs.size() > 1)
// 	{
// 		while (!sortedPairs.empty())
// 		{
// 			int first = sortedPairs.front();
// 			sortedPairs.pop_front();
			
// 			if (!sortedPairs.empty())
// 			{
// 				int second = sortedPairs.front();
// 				sortedPairs.pop_front();
				
// 				if (first > second)
// 					std::swap(first, second);
				
// 				auxPairs.push_back(first);
// 				auxPairs.push_back(second);
// 			}
// 			else
// 				auxPairs.push_back(first);
// 		}
// 		sortedPairs.swap(auxPairs);
// 	}
	
// 	mainChain.swap(sortedPairs);
	
// 	// Insertion of remaining elements
// 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
// 	{
// 		std::vector<int>::iterator insertionPos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
// 		mainChain.insert(insertionPos, *it);
// 	}
	
// 	// Print final sorted list
// 	for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	return ;
// }


/////////////////////////////  PARSING  /////////////////////////////

void	PmergeMe::parse(std::string str)
{
	// max number
	if (str.size() > 10000)
		throw TooMuchNbException();
	double	max = 0;
	for (int i = 0; str[i]; i++)
	{
		if (isDigit(str[i]) == false)
			throw WrongSyntaxException();
		max += std::atoi(&str[i]);
		if (max > INT_MAX)
			throw IntMaxException();
	}
}