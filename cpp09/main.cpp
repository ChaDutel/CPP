/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:45:12 by charline          #+#    #+#             */
/*   Updated: 2023/07/04 14:38:21 by charline         ###   ########.fr       */
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
	// for (int i = 0; argv[1][i]; i++)
	// {
	// 	if (parse(argv[1][i]) == -1)
	// 		return (0);
	// }

    std::ifstream inputFd(argv[1]);
    
    if (!inputFd.is_open())
	{
        std::cout << "ERROR : Error with the " << argv[1] << " file" << std::endl;
        return (0);
    }
    
    
    std::string	line;
	while (std::getline(inputFd, line, '\n'))
	{
		if (line == "date | value")
			continue;
        if (bitc.parse(line) == -1)
            return (0);
		// this->data[line.substr(0, 10)] = std::atof(line.substr(11).c_str());
		// if (line == "2009-01-02,999lp")
		// 	std::cout << line.substr(0, 10) << " " << std::atof(line.substr(11).c_str()) << std::endl;
	}
	inputFd.close();
    return (0);
}