/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/07 22:23:37 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	step1(std::vector<int>& container)//group the elements of pair to two
{
	int last_number = -1;
	std::vector<std::pair<int, int> > pair;
	if (container.size() % 2 == 1)
	{
		last_number = container.at(container.size() - 1);
		for(size_t i=0; i<container.size() - 1; i+=2)
			pair.push_back(std::make_pair(container.at(i), container.at(i + 1)));
	}
	else
	{
		for(size_t i=0; i<container.size(); i+=2)
			pair.push_back(std::make_pair(container.at(i), container.at(i + 1)));
	}
	for(size_t i=0; i<pair.size(); i++)
		std::cout << "[" << pair.at(i).first << ", " << pair.at(i).second << "]" << std::endl;
	if(last_number != -1)
		std::cout << "[" << last_number << "]" << std::endl;
}

void recursive_insertion_sort(int arr[], int n)
{ 
    // Base case 
    if (n <= 1) 
        return;
    // Sort first n-1 elements 
    // recursive_insertion_sort( arr, n-1 );
    int val = arr[n-1];
    int pos = n-2;
    while (pos >= 0 && arr[pos] > val) { 
        arr[pos+1] = arr[pos];
        pos = pos - 1;
    } 
    arr[pos+1] = val;
}

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::vector<int> container;
		int i = 1;
		while (argv[i])
		{
			if(isInteger(argv[i]) == 0)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			container.push_back(strtod(argv[i], NULL));
			i++;
		}
		std::cout << "Before:	";
		for(size_t i=0; i<container.size(); i++)
			std::cout << container.at(i) << " ";
		std::cout << std::endl;
		step1(container);
	}
	else
		std::cout << "Error" << std::endl;
	return 0;
}