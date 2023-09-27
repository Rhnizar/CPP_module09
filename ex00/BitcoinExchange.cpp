/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:06 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/27 23:52:19 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	CheckLine(std::string line)
{
	(void)line;
	return 0;
}

int	fillContainerWithData()
{
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
		if (CheckLine(line) == 1)
			return 1;
		container.push_back(line);
	}
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
