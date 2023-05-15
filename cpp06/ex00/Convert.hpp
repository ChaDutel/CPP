#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include  <cstdlib>

class	AForm;

class Convert
{
	public:
		Convert();
		Convert(char *argv);
		Convert(const Convert& other);
		Convert&	operator=(const Convert& other);
		~Convert();

		char	*getStr() const;
		int		findType(char *str);
		void	printGoodType(int identifiedType, char *str);

	private:
		char	*_str;
		int		isInfPos(std::string str);
		int		isInfNeg(std::string str);
		int		isInt(char *str);
		int		isFloat(char *str);
		int		isDouble(char *str);
		int		isChar(char *str);


		void	castInt(char * str);
		void	castFloat(char *str);
		void	castDouble(char *str);
		void	castChar(char *str);

		void	printResult(char c, int i, float f, double d);
		void	printExc(const char *c, const char *i, const char *f, const char *d);
};

# endif
