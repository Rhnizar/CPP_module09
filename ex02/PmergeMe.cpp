/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:27 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/07 13:07:30 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	isInteger(std::string str)
{
	double res = strtod(str.c_str(), NULL);
	if(res > 2147483647)
		return 0;
	for(size_t i=0; i<str.length(); i++)
	{
		if (str[i] == '+' && i == 0)
			continue;
		if (std::isdigit(str.at(i)) == 0)
			return 0;
	}
	return 1;
}