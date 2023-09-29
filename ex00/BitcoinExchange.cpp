/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:06 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/29 23:56:07 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	CheckLine(std::string line, int check)
{
	if (check == 0 && line != "date,exchange_rate")
		return 1;
	if(line != "date,exchange_rate")
	{
		check = 0;
		int	checkpoint = 0;
		int	checkmoin = 0;
		int checkvergil = 0;
		std::string year;
		std::string month;
		std::string day;
		std::string exchange_rate;
		if(line[0] == ',' || line[0] == '-' || line[line.length() - 1] == ',' || line[line.length() - 1] == '-'\
			|| line[0] == '.' || line[line.length() - 1] == '.' || line.length() == 0)
			return 1;
		for(size_t i=0; i<line.length(); i++)
		{
			if(line[i] == '-')
				checkmoin++;
			if(line[i] == ',')
				checkvergil++;
			if(line[i] == '.')
				checkpoint++;
			if ((isdigit(line[i]) == 0 && line[i] != '-' && line[i] != ',' && line[i] != '.') || \
				(checkmoin > 2 || checkpoint > 1 || checkvergil > 1))
				return 1;
		}
		for(size_t i=0; i<line.length(); i++)
		{
			if (line[i] == '-')
			{
				check++;
				i++;
			}
			if (check == 0)
				year += line[i];
			else if (check == 1)
				month += line[i];
			else if (check == 2)
			{
				if(line[i] == ',')
				{
					check = -10;
					i++;
				}
				else
					day += line[i];
			}
			if(check == -10)
				exchange_rate += line[i];
		}
		// std::cout << "===>  year  : " << year << std::endl;
		// std::cout << "===>  month : " << month << std::endl;
		// std::cout << "===>  day   : " << day << std::endl;
		// std::cout << "===>  exchange_rate   : " << exchange_rate << std::endl;
		// exit(1);
	}
	return 0;
}

int	fillContainerWithData()
{
	int check = 0;
	std::ifstream fileData;
	fileData.open("data.csv");
	std::vector<std::string> container;
	if(!fileData.is_open())
	{
		std::cout << "Error opening file the data ." << std::endl;
		return 2;
	}
	std::string line;
	while(std::getline(fileData, line))
	{
		if (CheckLine(line, check) == 1)
			return 1;
		container.push_back(line);
		check++;
	}
	if(container.size() == 0)
		return 1;
	return 0;
}

int findPipe(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if(str[i] == '|')
			return 1;
		i++;
	}
	return 0;
}
