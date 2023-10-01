/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:42:45 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/02 00:49:16 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	CheckString_AndFillContainer(std::string str)
{
	std::vector<int> container;
	std::vector<char> operators;
	int res = 0;
	for(size_t i=0; i<str.length(); i++)
	{
		if(isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '\t' && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if(str[i] == ' ' || str[i] == '\t')
			continue;
		if(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '/' || str[i + 1] == '*' || str[i + 1] == '\0')
		{
			if (str[i] != ' ' && str[i] != '\t')
			{
				if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
					container.push_back(str[i] - 48);
				else
					operators.push_back(str[i]);
			}
			if (container.size() >= 2 && operators.size() > 0)
			{
				int value1 = container.back();
				container.pop_back();
				int value2 = container.back();
				container.pop_back();
				// printf("value 1: %d\n", value1);
				// printf("value 2: %d\n", value2);
				char oper = operators.back();
				operators.pop_back();
				// printf("operator: %c\n", oper);
				if (oper == '+')
					res = value2 + value1;
				else if (oper == '-')
					res = value2 - value1;
				else if (oper == '*')
					res = value2 * value1;
				else if (oper == '/')
					res = value2 / value1;
				// printf("%d\n", res);
				container.push_back(res);
			}
		}
		else
		{
			std::cerr << "Error: number enter not  less than 10." << std::endl;
			return 1;
		}
	}
	std::cout << container.at(0) << std::endl;
	// std::cout << res << std::endl;
	// for(size_t i=0; i<container.size(); i++)
	// 	std::cout << container.at(i) << "  ";
	// std::cout << std::endl;
	// for(size_t i=0; i<operators.size(); i++)
	// 	std::cout << operators.at(i) << "  ";
	// std::cout << std::endl;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc==2)
	{
		if (CheckString_AndFillContainer(argv[1]) == 1)
			return 1;
	}
	else
	{
		std::cerr << "Usage: ./RPN <string>" << std::endl;
		return 1;
	}
	return 0;
}

/* result the how to calculate example 1
>>> 8*9
72
>>> 72 - 9
63
>>> 63 - 9
54
>>> 54 - 9
45
>>> 45 - 4
41
>>> 41 + 2
43
>>> 41 + 1
42
*/


/* result the how to calculate example 2
>>> 7 * 7
49
>>> 49 - 7
42
>>> */

 

 /* result the ./RPN "1 2 * 2 / 2 * 2 4 - +"
 1 2 * = 2
 2 / 2 = 1
 1 * 2 = 2
 2 - 4 = -2 
 2 + (-2) = 0
 */

