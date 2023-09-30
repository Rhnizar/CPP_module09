/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/30 13:15:52 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		std::vector<std::pair<std::string, std::string> > stringPair;
		if (fillContainerWithData(&stringPair) == 1)
		{
			std::cout << "error in databse !! " << std::endl;
			return 1;
		}
		// for(size_t i=0; i<stringPair.size(); i++)
		// 	std::cout << "date : " << stringPair.at(i).first << "  exchange_rate : " << stringPair.at(i).second << std::endl;
		std::ifstream file;
		file.open(argv[1]);
		if(!file.is_open())
		{
			std::cerr << "Error opening input file." << std::endl;
			return 1;
		}
		std::string line;
		std::string date;
		std::string value;
		while (std::getline(file, line))
		{
			int check = 0;
			if (line == "date | value")
				continue;
			if(findPipe(line) == 0)
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			for(size_t i=0; i<line.length();i++)
			{
				if (line[i] == '-' && check == 0)
					continue;
				else if (line[i] == '-' && check == 1)
				{
					std::cout << "Error: not a positive number." << std::endl;
					check = -9;
					break;
				}
				if (line[i] == '|')
				{
					check++;
					i++;
				}
				if (check == 0)
					date += line[i];
				else
					value += line[i];
			}
			if (check == -9)
				continue;
			double resValue = strtod(value.c_str(), NULL);
			double resDate = strtod(date.c_str(), NULL);
			(void)resDate;
			if (resValue > 2147483647)
			{
				std::cout << "Error: too large a number." << std::endl;
				date = "";
				value = "";
				continue;
			}
			for(size_t i=0; i<stringPair.size(); i++)
			{
				if(strtod(stringPair.at(i).first.c_str(), NULL) == resDate)
				{
					stringPair.at(i).first.insert(4, "-");
					stringPair.at(i).first.insert(7, "-");
					std::cout << stringPair.at(i).first.c_str() << " => " << resValue << " = " << resValue * strtod(stringPair.at(i).second.c_str(), NULL) << std::endl;
					break;
				}
			}
			date = "";
			value = "";
		}
		file.close();
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}
