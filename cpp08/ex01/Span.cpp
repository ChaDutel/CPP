/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:08:21 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/23 21:07:13 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

//----------------------------------------------------------------- BUILDERS -----------------------------------------------------------------//

Span::Span() : _nMax(0), _nMaxLeft(0)
{
}

Span::Span(int N) : _nMax(N), _nMaxLeft(N)
{
}

Span::~Span()
{
}

Span::Span(const Span& other)
{
	_nMax = other._nMax;
	_nMaxLeft = other._nMaxLeft;
}

Span& Span::operator=(const Span& other)
{
	_nMax = other._nMax;
	_nMaxLeft = other._nMaxLeft;
	return (*this);
}


//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

int		Span::shortestSpan()
{
	if (_nMax <= 1)
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
	if (_nMax <= 1)
		throw std::length_error("Error : Can't find the longest distance between two numbers because there are less than two numbers added");
	std::sort(_tab.begin(), _tab.end());
	return ((_tab.back()) - _tab.front());
}

void	Span::addNumber(int nb)
{
	if (_nMaxLeft != 0)
	{
		_tab.push_back(nb);
		--_nMaxLeft;
	}
}
