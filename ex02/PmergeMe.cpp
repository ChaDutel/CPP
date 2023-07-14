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

char const*	TooManyDigitException::what()			const throw() {return ("ERROR: Too many numbers to handle");}
char const*	IntMaxException::what()					const throw() {return ("ERROR: Number is greater than int max");}
char const*	WrongSyntaxException::what()	  		const throw() {return ("ERROR: Wrong syntax");}


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

/////////////////////////////   UTILS   /////////////////////////////

bool	PmergeMe::isDigit(char c)
{
	if (c > '9' || c < '0')
		return (false);
	return (true);
}


///////////////////////////// EXECUTION /////////////////////////////

// VECTOR

int PmergeMe::binaryFindVect(std::vector<int> vec, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

	// If the element is present at the middle
	// itself
	if (vec[mid] == x)
		return mid;
	else if (r - l == 1)
		return (r);
	// element present in left subarray
	else if (vec[mid] > x)
		return binaryFindVect(vec, l, mid, x);
	// else, element only present in right subarray
	return binaryFindVect(vec, mid, r, x);
}

void PmergeMe::addElemVect(std::vector<int> &chain, int value)
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
			int	index = binaryFindVect(chain, 0, chain.size() - 1, value);
			chain.insert(it + index, value);
		}
	}
}

std::vector<int>	PmergeMe::execVec(std::vector<int> vec)
{
	std::vector<int> chainSmaller;
	std::vector<int> chainGreater;

	while (!vec.empty())
	{
		std::vector<int>::iterator it = vec.begin();
		int first = vec.front();
		vec.erase(it);
		if (!vec.empty())
		{
			it = vec.begin();
			int second = vec.front();
			vec.erase(it);
			if (first > second)
			{
				chainGreater.push_back(first);
				addElemVect(chainSmaller, second);
			}
			else
			{
				chainGreater.push_back(second);
				addElemVect(chainSmaller, first);
			}
		}
		else
			addElemVect(chainSmaller, first);
	}
	while (!chainGreater.empty())
	{
		std::vector<int>::iterator it = chainGreater.begin();
		int first = chainGreater.front();
		chainGreater.erase(it);
		addElemVect(chainSmaller, first);
	}
	return (chainSmaller);
}

// LIST

int PmergeMe::binaryFindLi(std::list<int> li, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

	std::list<int>::iterator	it = li.begin();
	for (int i = 0; i < mid; i++)
		++it;
	if (*it == x)
		return mid;
	else if (r - l == 1)
		return (r);
	// element present in left subarray
	else if (*it > x)
		return binaryFindLi(li, l, mid, x);
	// else, element only present in right subarray
	return binaryFindLi(li, mid, r, x);
}

void PmergeMe::addElemLi(std::list<int> &chain, int value)
{
	std::list<int>::iterator	it = chain.begin();
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
			int	index = binaryFindLi(chain, 0, chain.size() - 1, value);
			std::advance(it, index);
			chain.insert(it, value);
		}
	}
}

void	PmergeMe::execLi(std::list<int> li)
{
	std::list<int> chainSmaller;
	std::list<int> chainGreater;

	while (!li.empty())
	{
		std::list<int>::iterator it = li.begin();
		int first = li.front();
		li.erase(it);
		if (!li.empty())
		{
			it = li.begin();
			int second = li.front();
			li.erase(it);
			if (first > second)
			{
				chainGreater.push_back(first);
				addElemLi(chainSmaller, second);
			}
			else
			{
				chainGreater.push_back(second);
				addElemLi(chainSmaller, first);
			}
		}
		else
			addElemLi(chainSmaller, first);
	}
	while (!chainGreater.empty())
	{
		std::list<int>::iterator it = chainGreater.begin();
		int first = chainGreater.front();
		chainGreater.erase(it);
		addElemLi(chainSmaller, first);
	}
	return ;
}


/////////////////////////////  PARSING  /////////////////////////////

void	PmergeMe::parse(std::string str)
{
	// max number
	if (str.size() > 10)
		throw TooManyDigitException();
	double	max = 0;
	for (int i = 0; str[i]; i++)
	{
		if (isDigit(str[i]) == false)
			throw WrongSyntaxException();
	}
	max = std::atof(str.c_str());
	if (max > 2147483647)
		throw IntMaxException();
}
