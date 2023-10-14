/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:15 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/14 20:50:21 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // Include the <cstdlib> for strtod
#include <vector>
#include <unistd.h>


class PmergeMe
{
	public:
		std::vector<int> container;
		std::vector<std::vector<int> > VectordyalXyata;
		std::vector<std::vector<int> > mainChaine;
		std::vector<std::vector<int> > pend;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pairR;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
		
		int		numElements;
		void	printBefore();
		void	printAfter();
		int		fillContainer(char **argv);
		
		void	MergeInsertSort(size_t sizeVectorPair);
		void	LastRecursion();
		void	ReverseRecursion(size_t sizeVectorPair);
		PmergeMe(){}
		~PmergeMe(){}

};

int	isInteger(std::string str);