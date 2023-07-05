/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:45:12 by charline          #+#    #+#             */
/*   Updated: 2023/07/05 15:02:51 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "ERROR : Wrong number of arguments";
        return (0);
    }
    std::ifstream dataFd("data.csv");
    
    if (!dataFd.is_open())
	{
        std::cout << "ERROR : Error with the " << argv[1] << " file" << std::endl;
        return (0);
    }
	BitcoinExchange bitc(dataFd);
	dataFd.close();

    std::ifstream inputFd(argv[1]);
    
    if (!inputFd.is_open())
	{
        std::cout << "ERROR : Error with the " << argv[1] << " file" << std::endl;
        return (0);
    }

    bool    isFirstLine = true;
    std::string	line;
	while (std::getline(inputFd, line, '\n'))
	{
		if (line == "date | value" && isFirstLine == true)
        {
            isFirstLine = false;
			continue;
        }
        if (bitc.parse(line) == -1)
            continue;
        bitc.exec(line.substr(0, 10), std::atof(line.substr(13).c_str()));
	}
	inputFd.close();
    return (0);
}