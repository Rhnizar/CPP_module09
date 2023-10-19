/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:15 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/19 11:29:53 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // Include the <cstdlib> for strtod
#include <vector>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <list>
#include <algorithm>


class PmergeMe
{
	public:
		std::vector<int> container;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pairR;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
		
		int		numElements;
		void	printBefore();
		void	printAfter();
		int		fillContainer(char **argv);
		
		void	MergeInsertSort(size_t sizeVectorPair);
		void	ReverseRecursion(size_t sizeVectorPair, std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine, std::vector<std::vector<int> >& pend);
		void	LastRecursion(size_t sizeVectorPair,  std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine);
		/*jacobsthal*/
		// void	generateJacobIndex();
		int		jacobsthal(size_t index);
		std::vector<int> jacobSequence;
		PmergeMe(){}
		~PmergeMe(){}

		/*list*/
		std::list<int> ListContainer;
		std::list<std::pair<std::list<int>, std::list<int> > > LpairR;
		std::list<std::pair<std::list<int>, std::list<int> > > Lpair;
		void	MergeInsertSort_For_List(size_t sizeListrPair);
		void	LastRecursion_For_List(size_t sizeListPair,  std::list<int>& ListDyalXyata, std::list<std::list<int> >& mainChaine);
		void	ReverseRecursion_For_List(size_t sizeVectorPair, std::list<int>& ListDyalXyata, std::list<std::list<int> >& mainChaine, std::list<std::list<int> >& pend);

		
		void	usingList(size_t sizeListPair);
};

int	isInteger(std::string str);