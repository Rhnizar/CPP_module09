/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:06 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/01 13:09:45 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	CheckDay(int day, int month)
{
	if (day < 1 || day > 31)
		return 1;
	if (month >= 1 && month <= 7)
	{
		if(month % 2 == 0 && day == 31 && month != 2)
			return 1;
	}
	if (month >= 8 && month <= 12 && month != 2)
	{
		if(month % 2 == 1 && day == 31)
			return 1;
	}
	if (month == 2)
	{
		if (day > 29)
			return 1;
	}
	return 0;
}

int	CheckYearMonthDay(std::string year, std::string month, std::string day)
{
	double resYear = strtod(year.c_str(), NULL);
	double resMonth = strtod(month.c_str(), NULL);
	double resDay = strtod(day.c_str(), NULL);
	if (resYear < 2009 || resYear > 2023)
		return 1;
	if (resMonth < 1 || resMonth > 12)
		return 1;
	if (CheckDay(resDay, resMonth) == 1)
		return 1;
	if (resYear == 2009 && resMonth == 1 && resDay < 3)
		return 1;
	return 0;
}


int	CheckExchange_rate(std::string exchange_rate)
{
	double res = strtod(exchange_rate.c_str(), NULL);
	(void)res;
	return 0;
}

int	CheckLine(std::string line, int check, std::string *date, std::string *exchange_rate)
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
		if(checkmoin != 2 || checkvergil != 1)
			return 1;
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
				*exchange_rate += line[i];
		}
		if(CheckYearMonthDay(year, month, day) == 1 || CheckExchange_rate(*exchange_rate) == 1)
			return 1;
		(*date).append(year);
		(*date).append(month);
		(*date).append(day);
	}
	return 0;
}

int	fillContainerWithData(std::vector<std::pair<std::string, std::string> > *stringPair)
{
	int check = 0;
	std::ifstream fileData;
	fileData.open("data.csv");
	std::string date;
	std::string exchange_rate;
	if(!fileData.is_open())
	{
		std::cout << "Error opening file the data ." << std::endl;
		return 2;
	}
	std::string line;
	while(std::getline(fileData, line))
	{
		if (CheckLine(line, check, &date, &exchange_rate) == 1)
			return 1;
		(*stringPair).push_back(std::make_pair(date, exchange_rate));
		check++;
		date = "";
		exchange_rate = "";
	}
	if((*stringPair).size() == 0)
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
