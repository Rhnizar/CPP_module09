/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:41:18 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/02 12:40:25 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	CheckString_AndFillContainer(std::string str)
{
	std::deque<int> container;
	std::deque<char> operators;
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
	if (operators.size() == 0 && container.size() == 1)
		std::cout << container.at(0) << std::endl;
	else
		throw  std::runtime_error("Error: invalid format .");
	return 0;
}
