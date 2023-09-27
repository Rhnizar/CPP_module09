/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/27 23:51:10 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		if (fillContainerWithData() == 1)
		{
			std::cout << "error in databse !! " << std::endl;
			return 1;
		}
		std::ifstream file;
		file.open(argv[1]);
		if(!file.is_open())
		{
			std::cerr << "Error opening input file." << std::endl;
			return 1;
		}
		std::string line;
		while (std::getline(file, line))
		{
			if(findPipe(line) == 0)
				std::cout << "Error: bad input => " << line << std::endl;
		}
		file.close();
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}
