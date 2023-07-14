#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <ctime>
# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		// parsing
		void   				parse(std::string str);

		// execution
		std::vector<int>	execVec(std::vector<int> vec);
		void				addElemVect(std::vector<int> &chain, int value);
		int					binaryFindVect(std::vector<int> vec, int l, int r, int x);

		void				execLi(std::list<int> li);
		void				addElemLi(std::list<int> &chain, int value);
		int					binaryFindLi(std::list<int> li, int l, int r, int x);

		// utils
		bool				isDigit(char c);

	private:
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
};

class	TooManyDigitException				: public std::exception {public: virtual char const*	what() const throw();};
class	IntMaxException						: public std::exception {public: virtual char const*	what() const throw();};
class	WrongSyntaxException 				: public std::exception {public: virtual char const*	what() const throw();};

# endif
