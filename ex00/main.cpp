/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/06 19:01:20 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkInput(std::ifstream& file, std::vector<std::pair<std::string, std::string> >& stringPair)
{
	std::string line;
	std::string date;
	std::string value;
	std::string year;
	std::string month;
	std::string day;
	int checkLine1 = 0;
	int	checkPoint = 0;
	while (std::getline(file, line))
	{
		int check = 0;
		if (line == "date | value" && checkLine1 == 0)
		{
			checkLine1++;
			continue;
		}
		if(findPipe(line) == 0)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		for(size_t i=0; i<line.length();i++)
		{
			if (line[i] == '.')
				checkPoint++;
			if ((line[i] == '-' && check == 0 && i == 4) || (line[i] == '-' && check == 0 && i == 7))
				continue;
			else if (line[i] == '-' && check == 1)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				check = -9;
				break;
			}
			else if ((isdigit(line[i]) == 0 && line[i] != '-' && line[i] != ' ' &&  line[i] != '|' && line[i] != '.')\
				 || (line[i] == '-' && i != 4 && i != 7) || (checkPoint > 1))
			{
				std::cerr << "Error: bad input => " << line << std::endl;
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
		{
			date = "";
			value = "";
			continue;
		}
		double resValue = strtod(value.c_str(), NULL);
		double resDate = strtod(date.c_str(), NULL);
		if (resValue > 2147483647)
		{
			std::cerr << "Error: too large a number." << std::endl;
			date = "";
			value = "";
			continue;
		}
		for(size_t i=0; i<date.length();i++)
		{
			if(i < 4)
				year += date[i];
			else if(i < 6)
				month += date[i];
			else if(i < 8)
				day += date[i];
		}
		if(CheckYearMonthDay(year, month, day) == 1)
		{
			std::cerr << "Error: in this  date " << year << "-" << month << "-" << day << std::endl;
			date = "";
			value = "";
			year = "";
			month = "";
			day = "";
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
			date.insert(4, "-");
			date.insert(7, "-");
			std::cout << date.c_str() << " => " << resValue << " = " << resValue * strtod(stringPair.at(index).second.c_str(), NULL) << std::endl;
		}
		date = "";
		value = "";
		year = "";
		month = "";
		day = "";
	}
	return 0;
}

int main(int argc, char **argv)
{
	if(argc == 2)
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
		std::cerr << "Usage: ./btc <input.txt>" << std::endl;
	return 0;
}
