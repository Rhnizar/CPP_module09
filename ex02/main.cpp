/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/11 00:47:15 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	step1(PmergeMe& pmergeMe, size_t sizeVectorPair)
{
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
	int xyata = pmergeMe.container.size() % (sizeVectorPair * 2);

    for (size_t i = 0; i < pmergeMe.container.size(); i += sizeVectorPair * 2) 
	{
        std::vector<int> LeftVector;
        std::vector<int> RightVector;
	
		if(i != pmergeMe.container.size() - xyata)
		{
        	for (size_t j = i; j < i + sizeVectorPair; j++)
        	    LeftVector.push_back(pmergeMe.container.at(j));
	
        	for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
        	    RightVector.push_back(pmergeMe.container.at(j));
			
        	if (LeftVector.back() > RightVector.back())
			{
        	    int tmp = LeftVector.back();
        	    LeftVector.back() = RightVector.back();
        	    RightVector.back() = tmp;
        	}
        	pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			for(size_t l=pmergeMe.container.size() - xyata; l<pmergeMe.container.size(); l++)
				pmergeMe.VectordyalXyata.push_back(pmergeMe.container.at(l));
		}
    }
    // empty lcontainer hna
	pmergeMe.container.clear();
	// fill lcontainer hna
	for (size_t i = 0; i < pair.size(); i++)
	{
		for(size_t j=0; j<pair.at(i).first.size(); j++)
			pmergeMe.container.push_back(pair.at(i).first.at(j));
		for(size_t k=0; k<pair.at(i).second.size(); k++)
			pmergeMe.container.push_back(pair.at(i).second.at(k));
	}
    for (size_t i = 0; i < pair.size(); i++) 
	{
        // Access elements within each pair
		std::cout << "[";
		for(size_t j=0; j<pair.at(i).first.size(); j++)
			std::cout << pair.at(i).first.at(j) << " ";
		std::cout << ",";
		for(size_t k=0; k<pair.at(i).second.size(); k++)
			std::cout << pair.at(i).second.at(k) << " ";
		std::cout << "]" << std::endl;
        // std::cout << "[" << pair.at(i).first.at(pair.at(i).first.size() -1) << ", " << pair.at(i).second.at(pair.at(i).second.size() -1) << "]" << std::endl;
    }
	sizeVectorPair *= 2;
	
	if (pair.size() == 1)
		return ;
	
	step1(pmergeMe, sizeVectorPair);
	pair.clear();
	// std::cout << "sizeVectorPair: " << sizeVectorPair << std::endl;
	// exit(1);
	sizeVectorPair /= 2;
	for (size_t i = 0; i < pmergeMe.container.size(); i += sizeVectorPair * 2)
	{
		std::vector<int> LeftVector2;
        std::vector<int> RightVector2;
		
		for (size_t j = i; j < i + sizeVectorPair; j++)
        	LeftVector2.push_back(pmergeMe.container.at(j));
	
        for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
        	RightVector2.push_back(pmergeMe.container.at(j));
		pair.push_back(std::make_pair(LeftVector2, RightVector2));
	}
	// pmergeMe.mainChaine.reserve(pair.size());
	for(size_t i=0; i<pair.size();i++)
	{
		pmergeMe.mainChaine.push_back(pair.at(i).second);
		pmergeMe.pend.push_back(pair.at(i).first);

	}
	// exit(1);
	std::cout << "main Chain" << std::endl;
	for(size_t i=0; i<pmergeMe.mainChaine.size();i++)
	{
		for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
			std::cout << pmergeMe.mainChaine.at(i).at(j) << " ";
	}
	std::cout << "\npend" << std::endl;
	for(size_t i=0; i<pmergeMe.pend.size();i++)
	{
		for(size_t j=0; j<pmergeMe.pend.at(i).size();j++)
			std::cout << pmergeMe.pend.at(i).at(j) << " ";
	}
	std::cout << std::endl;
	exit(1);
	// empty lcontainer hna
	// pmergeMe.container.clear();
	// // fill lcontainer hna
	// for (size_t i = 0; i < pair.size(); i++)
	// {
	// 	for(size_t j=0; j<pair.at(i).first.size(); j++)
	// 		pmergeMe.container.push_back(pair.at(i).first.at(j));
	// 	for(size_t k=0; k<pair.at(i).second.size(); k++)
	// 		pmergeMe.container.push_back(pair.at(i).second.at(k));
	// }
	// for(size_t r=0; r<pmergeMe.container.size(); r++)
	// 	std::cout << pmergeMe.container.at(r) << " ";
	// std::cout << std::endl;
	// std::cout << "size: " << pair.size() << std::endl;
}
/*1 2 6 9 3 2 10 3 7*/
int main(int argc, char **argv)
{
	if (argc > 2)
	{
		PmergeMe pmergeMe;
		int i = 1;
		while (argv[i])
		{
			if(isInteger(argv[i]) == 0)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			pmergeMe.container.push_back(strtod(argv[i], NULL));
			i++;
		}
		std::cout << "Before:	";
		for(size_t i=0; i<pmergeMe.container.size(); i++)
			std::cout << pmergeMe.container.at(i) << " ";
		std::cout << std::endl;
		step1(pmergeMe, 1);
		
		// print container after recursion
		// std::cout << "container after recursion :" << std::endl;
		// for(size_t i=0; i<pmergeMe.container.size(); i++)
		// 	std::cout << pmergeMe.container.at(i) << " " ;
		// std::cout << std::endl;
		// std::cout << "container dyal xyata after recursion :" << std::endl;
		// for(size_t i=0; i<pmergeMe.VectordyalXyata.size(); i++)
		// 	std::cout << pmergeMe.VectordyalXyata.at(i) << " " ;
		// std::cout << std::endl;
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
	return 0;
}