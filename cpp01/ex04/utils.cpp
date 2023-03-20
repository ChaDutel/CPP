/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:50 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 12:33:48 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	compareStrings(std::string str, std::string strOld, std::string strNew)
{
	std::string				finalString;
	std::string::size_type	n;
	
	finalString = str;
	if (strOld == "" || strNew == "")
		return (finalString);
	n = finalString.find(strOld);
	while (std::string::npos != n)
	{
        finalString.erase(n, strOld.length());
		finalString.insert(n, strNew);
		n = finalString.find(strOld, n + strNew.length());
	}
	return (finalString);
}

void	manageFiles(char **argv)
{
	std::fstream	firstFile;
	std::string		tmpargv;
	
	tmpargv = argv[1];
	firstFile.open(tmpargv.c_str(), std::ios::in);
	if (!firstFile || firstFile.fail())
	{
		std::cout << "Fail to open file!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "File opened successfully!" << std::endl;
	}
	
	std::fstream	newtFile;
	std::string		myNewFile;
	std::string		tmp;
	
	tmp = argv[1];
	myNewFile = tmp + ".replace";
	newtFile.open(myNewFile.c_str(), std::ios::out);
	if (!newtFile || newtFile.fail())
	{
		std::cout << "Fail to create file!" << std::endl;
		firstFile.close();
		return ;
	}
	else
	{
		std::cout << "The replace file created successfully!" << std::endl;
		std::string line;
		std::string str;
		while (firstFile.good())
		{
			if (std::getline(firstFile, line) != 0)
				str += line + '\n';
		}
		str = compareStrings(str, argv[2], argv[3]);
		newtFile << str;
		newtFile.close();
	}
	firstFile.close();
}
