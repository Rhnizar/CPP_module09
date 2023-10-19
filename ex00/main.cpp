/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/19 15:04:47 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkInput(std::ifstream& file, std::set<std::pair<std::string, std::string> >& stringPair)
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
		if (resValue > 1000 && resValue < 2147483648)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			date = "";
			value = "";
			continue;
		}
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
		size_t i = 0;
		std::set<std::pair<std::string, std::string> >::iterator it;
		it = stringPair.begin();
		for(; it != stringPair.end(); it++)
		{
			if(strtod(it->first.c_str(), NULL) == resDate)
			{
				std::string first = it->first;
				first.insert(4, "-");
				first.insert(7, "-");
				std::cout << first.c_str() << " => " << resValue << " = " << resValue * strtod(it->second.c_str(), NULL) << std::endl;
				break;
			}
			i++;
		}
		if (i == stringPair.size())
		{
			int tmpDate = resDate;
			std::set<std::pair<std::string, std::string> >::iterator it;
			std::set<std::pair<std::string, std::string> >::iterator tmp_it;
			it = stringPair.begin();
			for(; it != stringPair.end(); it++)
			{
				double res = strtod(it->first.c_str(), NULL);
				if (res < resDate && tmpDate == resDate)
				{
					tmpDate = res;
					tmp_it = it;
				}
				if (res < resDate && res > tmpDate)
				{
					tmpDate = res;
					tmp_it = it;
				}
			}
			date.insert(4, "-");
			date.insert(7, "-");
			std::cout << date.c_str() << " => " << resValue << " = " << resValue * strtod(tmp_it->second.c_str(), NULL) << std::endl;
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
		std::set<std::pair<std::string, std::string> > stringPair;
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
