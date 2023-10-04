/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSortTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:58 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/03 16:51:27 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
std::vector<int> container;

void MergePart(int LowerIndex, int middle, int HigherIndex)
{
	
}

void	doMergeSort(int LowerIndex, int HigherIndex)
{
	int middle = LowerIndex + (HigherIndex - LowerIndex) / 2;
	doMergeSort(LowerIndex, middle);
	doMergeSort(middle + 1, HigherIndex);
	MergePart(LowerIndex, middle, HigherIndex);
}
int main()
{
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	std::cout << "numbers before sort: " << std::endl;
	for(size_t i=0; i<container.size(); i++)
		std::cout << container.at(i) << " ";
	std::cout << std::endl;

	doMergeSort(0, container.size() - 1);
	std::cout << "numbers after sort: " << std::endl;
	for(size_t i=0; i<container.size(); i++)
		std::cout << container.at(i) << " ";
	std::cout << std::endl;
	return 0;
}