/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/17 17:57:20 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of parameters\n";
		return (0);
	}
	manageFiles(argv);
}

// int	doFileReplace(std::fstream	firstFile, char **argv)
// {
// 	std::fstream	newtFile;
// 	std::string		myNewFile;
// 	std::string		tmp;

// 	tmp = argv[1];
// 	myNewFile = tmp + ".replace";
// 	newtFile.open(myNewFile.c_str(), std::ios::out);
// 	if (!newtFile || newtFile.fail())
// 	{
// 		std::cout << "File2 not created!" << std::endl;
// 		return (-1);
// 	}
// 	else
// 	{
// 		std::cout << "File2 created successfully!" << std::endl;
// 		std::string line;
// 		std::string str;
// 		while (firstFile.good())
// 		{
// 			if (std::getline(firstFile, line) != 0)
// 				str += line + '\n';
// 		}
// 		str = compareStrings(str, argv[2], argv[3]);
// 		newtFile << str;
// 		newtFile.close();
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc != 4)
// 	{
// 		std::cout << "Error: Wrong number of parameters\n";
// 		return (0);
// 	}
// 	std::fstream	firstFile;
// 	std::string		tmpargv;
// 	tmpargv = argv[1];
// 	firstFile.open(tmpargv.c_str(), std::ios::in);
// 	if (!firstFile || firstFile.fail())
// 	{
// 		std::cout << "File1 not created!" << std::endl;
// 		return (0);
// 	}
// 	else
// 	{
// 		std::cout << "File1 created successfully!" << std::endl;
// 	}
// 	if (doFileReplace(firstFile, argv) == -1)
// 	{
// 		firstFile.close();
// 		return (0);
// 	}
// 	firstFile.close();
// }

/* int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of parameters\n";
		return (0);
	}
	std::fstream	firstFile;
	std::string		tmpargv;
	tmpargv = argv[1];
	firstFile.open(tmpargv.c_str(), std::ios::in);
	if (!firstFile || firstFile.fail())
	{
		std::cout << "File1 not created!" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "File1 created successfully!" << std::endl;
	}
	
	std::fstream	newtFile;
	std::string		myNewFile;
	std::string		tmp;
	tmp = argv[1];
	myNewFile = tmp + ".replace";
	newtFile.open(myNewFile.c_str(), std::ios::out);
	if (!newtFile || newtFile.fail())
	{
		std::cout << "File2 not created!" << std::endl;
		firstFile.close();
		return (0);
	}
	else
	{
		std::cout << "File2 created successfully!" << std::endl;
		std::string line;
		std::string str;
		while (firstFile.good())
		{
			if (std::getline(firstFile, line) != 0)
				str += line + '\n';
			// str.append(1, firstFile.get());
		}
		// while (std::getline(firstFile, line))
		// {
		// 	str += line + '\n';
		// 	// str.append(1, firstFile.get());
		// }
		// while (firstFile.good())
		// {
		// 	// str.append(1, firstFile.get());
		// }
		str = compareStrings(str, argv[2], argv[3]);
		newtFile << str;
		newtFile.close();
	}
	firstFile.close();
} */
