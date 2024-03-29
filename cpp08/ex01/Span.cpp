/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:08:21 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/25 14:34:15 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

//----------------------------------------------------------------- BUILDERS -----------------------------------------------------------------//

Span::Span() : _nAdded(0), _nMaxLeft(0)
{
}

Span::Span(int N) : _nAdded(0), _nMaxLeft(N)
{
}

Span::~Span()
{
}

Span::Span(const Span& other)
{
	_nAdded = other._nAdded;
	_nMaxLeft = other._nMaxLeft;
}

Span& Span::operator=(const Span& other)
{
	_nAdded = other._nAdded;
	_nMaxLeft = other._nMaxLeft;
	return (*this);
}


//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

int		Span::shortestSpan()
{
	if (_nAdded <= 1)
		throw std::length_error("Error : Can't find the shortest distance between two numbers because there are less than two numbers added");

	std::sort(_tab.begin(), _tab.end());
	int	short_value = 2147483647;
	int	j;
	for (unsigned long i = 0; (i + 1) < _tab.size(); ++i)
	{
		j = _tab[i + 1] - _tab[i];
		if (j < short_value)
			short_value = j;
	}
	return (short_value);
}

int		Span::longestSpan()
{
	if (_nAdded <= 1)
		throw std::length_error("Error : Can't find the longest distance between two numbers because there are less than two numbers added");
	std::sort(_tab.begin(), _tab.end());
	return ((_tab.back()) - _tab.front());
}

void	Span::addNumber(int nb)
{
	if (_nMaxLeft != 0)
	{
		_tab.push_back(nb);
		++_nAdded;
		--_nMaxLeft;
	}
	else
		throw std::out_of_range("Error : Can't add more number");
}
