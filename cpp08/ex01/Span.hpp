#ifndef	SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	public:
		Span();
		Span(int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int nb);

	private:
		int					_nMax;
		int					_nMaxLeft;
		std::vector<int> 	_tab;
};

# endif
