/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:27 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/21 00:04:33 by rrhnizar         ###   ########.fr       */
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

int	PmergeMe::fillContainer(char **argv)
{
	int i = 1;
	numElements = 0;
	while (argv[i])
	{
		if(isInteger(argv[i]) == 0)
			return 1;
		numElements++;
		i++;
	}
	i = 1;
	container.reserve(numElements);
	while (argv[i])
	{
		container.push_back(strtod(argv[i], NULL));
		ListContainer.push_back(strtod(argv[i], NULL));
		i++;
	}
	return 0;
}

void	PmergeMe::printBefore()
{
	std::cout << "Before:	";
	for(size_t i=0; i<container.size(); i++)
		std::cout << container.at(i) << " ";
	std::cout << std::endl;
}

void	PmergeMe::printAfter()
{
	std::cout << "After:	";
	for(size_t i=0; i<container.size(); i++)
		std::cout << container.at(i) << " ";
	std::cout << std::endl;
}


void	PmergeMe::printListBefore()
{
	std::cout << "Before: " << std::endl;
	for(std::list<int>::iterator it=ListContainer.begin(); it != ListContainer.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printListAfter()
{
	std::cout << "\ncontainer after recursion :" << std::endl;
	for(std::list<int>::iterator it=ListContainer.begin(); it != ListContainer.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*jacobsthal*/

int		PmergeMe::jacobsthal(size_t n)
{
	return ((pow(2, n +1) + pow(-1, n)) / 3);
}

