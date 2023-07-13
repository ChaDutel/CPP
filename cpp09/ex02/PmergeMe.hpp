#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
# include <iostream>
# include <list>
# include <vector>
// # include <fstream>

class PmergeMe
{
	public:
		PmergeMe();
		// PmergeMe(/**/);
		~PmergeMe();

		// getters and setters
		// std::stack<double> 	getNbStack();
		// void 				addNb(double nb);
		// double				removeNb();

		// parsing
		void    parse(std::string str);

		// execution
		// void	execLi(std::list<int> li);
		void	execVec(std::vector<int> vec);

		// utils
		bool	isDigit(char c);
		bool	isOperator(char c);

	private:
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);

		// std::stack<double> nbStack;
};

class	TooMuchNbException					: public std::exception {public: virtual char const*	what() const throw();};
class	IntMaxException						: public std::exception {public: virtual char const*	what() const throw();};
class	WrongSyntaxException 				: public std::exception {public: virtual char const*	what() const throw();};
// class	TooFewNumberException 				: public std::exception {public: virtual char const*	what() const throw();};
// class	TooFewNumbersException 				: public std::exception {public: virtual char const*	what() const throw();};
// class	TooMuchNumbersException	 			: public std::exception {public: virtual char const*	what() const throw();};
// class	ZeroDivException					: public std::exception {public: virtual char const*	what() const throw();};

# endif