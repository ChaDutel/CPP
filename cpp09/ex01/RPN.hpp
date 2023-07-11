#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <stack>

class RPN
{
	public:
		RPN();
		// RPN(/**/);
		~RPN();

		// getters and setters
		std::stack<double> 	getNbStack();
		void 				addNb(double nb);
		double				removeNb();

		// parsing
		void    parse(std::string str);

		// execution
		void	exec(char c);

		// utils
		bool	isDigit(char c);
		bool	isOperator(char c);

	private:
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

		std::stack<double> nbStack;
};

class	WrongSyntaxException 				: public std::exception {public: virtual char const*	what() const throw();};
class	TooFewNumberException 				: public std::exception {public: virtual char const*	what() const throw();};
class	TooFewNumbersException 				: public std::exception {public: virtual char const*	what() const throw();};
class	TooMuchNumbersException	 			: public std::exception {public: virtual char const*	what() const throw();};
class	TooMuchNbOrOpException				: public std::exception {public: virtual char const*	what() const throw();};
class	ZeroDivException					: public std::exception {public: virtual char const*	what() const throw();};

# endif