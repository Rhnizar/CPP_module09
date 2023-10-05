/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/05 15:40:12 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkInput(std::ifstream& file, std::vector<std::pair<std::string, std::string> >& stringPair)
{
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
				std::cerr << "Error: not a positive number." << std::endl;
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
		if (resValue > 2147483647)
		{
			std::cerr << "Error: too large a number." << std::endl;
			date = "";
			value = "";
			continue;
		}
		size_t i;
		for(i=0; i<stringPair.size(); i++)
		{
			if(strtod(stringPair.at(i).first.c_str(), NULL) == resDate)
			{
				
				stringPair.at(i).first.insert(4, "-");
				stringPair.at(i).first.insert(7, "-");
				std::cout << stringPair.at(i).first.c_str() << " => " << resValue << " = " << resValue * strtod(stringPair.at(i).second.c_str(), NULL) << std::endl;
				break;
			}
		}
		int tmpDate = resDate;
		size_t	index = 0;
		if (i == stringPair.size())
		{
			for(size_t i=0; i<stringPair.size(); i++)
			{
				double res = strtod(stringPair.at(i).first.c_str(), NULL);
				if (res < resDate && tmpDate == resDate)
					tmpDate = res;
				if (res < resDate && res > tmpDate)
				{
					tmpDate = res;
					index = i;
				}
			}
			std::cout << stringPair.at(index).first.c_str() << " => " << resValue << " = " << resValue * strtod(stringPair.at(index).second.c_str(), NULL) << std::endl;
		}
		date = "";
		value = "";
	}
	return 0;
}

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		std::vector<std::pair<std::string, std::string> > stringPair;
		int re = fillContainerWithData(&stringPair);
		if (re == 1)
		{
			std::cerr << "error in databse !! " << std::endl;
			return 1;
		}
		else if (re == 2)
			return 1;
		std::ifstream file;
		file.open(argv[1]);
		if(!file.is_open())
		{
			std::cerr << "Error opening input file." << std::endl;
			return 1;
		}
		checkInput(file, stringPair);
		file.close();
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
	return 0;
}
