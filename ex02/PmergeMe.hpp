/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:15 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/16 21:53:05 by rrhnizar         ###   ########.fr       */
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
		std::vector<std::vector<int> > VectordyalXyata;
		std::vector<std::vector<int> > mainChaine;
		std::vector<std::vector<int> > pend;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pairR;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;

		std::vector<std::vector<std::vector<int> >::iterator> Vecit;
		
		int		numElements;
		void	printBefore();
		void	printAfter();
		int		fillContainer(char **argv);
		
		void	MergeInsertSort(size_t sizeVectorPair);
		void	LastRecursion();
		void	ReverseRecursion(size_t sizeVectorPair);
		/*jacobsthal*/
		// void	generateJacobIndex();
		int		jacobsthal(size_t index);
		std::vector<int> jacobSequence;
		PmergeMe(){}
		~PmergeMe(){}

		/*list*/

		std::list<int> containerList;
		std::list<std::list<int> > listdyalXyata;
		std::list<std::list<int> > mainChaineList;
		std::list<std::list<int> > pendList;
		std::list<std::pair<std::list<int>, std::list<int> > > LpairR;
		std::list<std::pair<std::vector<int>, std::vector<int> > > Lpair;
		
		void	usingList(size_t sizeListPair);
};

int	isInteger(std::string str);