/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/12 00:45:48 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
    // return cmp1.back() <= cmp2.back();
    return cmp1.back() > cmp2.back();
}

int binarySearch(std::vector<std::vector<int> > array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid).back())
			return (mid);

		if (target > array.at(mid).back())
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid).back())
		return (mid + 1);
	else
		return (mid);
}

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
				pair.push_back(std::make_pair(RightVector, LeftVector));
			else
        		pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			std::vector<int> xy;
			for(size_t l=pmergeMe.container.size() - xyata; l<pmergeMe.container.size(); l++)
				xy.push_back(pmergeMe.container.at(l));
			pmergeMe.VectordyalXyata.push_back(xy);
		}
    }
	// exit(1);
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
    // for (size_t i = 0; i < pair.size(); i++) 
	// {
    //     // Access elements within each pair
	// 	std::cout << "[";
	// 	for(size_t j=0; j<pair.at(i).first.size(); j++)
	// 		std::cout << pair.at(i).first.at(j) << " ";
	// 	std::cout << ",";
	// 	for(size_t k=0; k<pair.at(i).second.size(); k++)
	// 		std::cout << pair.at(i).second.at(k) << " ";
	// 	std::cout << "]" << std::endl;
    // }
	sizeVectorPair *= 2;
	
	if (pair.size() == 1)
		return ;
	
	step1(pmergeMe, sizeVectorPair);
	pair.clear();
	sizeVectorPair /= 2;
	if(pmergeMe.container2.size() == 0)
		pmergeMe.container2 = pmergeMe.container;
	(pmergeMe.i) += 1;
	
	for (size_t i = 0; i < pmergeMe.container2.size(); i += sizeVectorPair * 2)
	{
		std::vector<int> LeftVector2;
        std::vector<int> RightVector2;
	
		for (size_t j = i; j < i + sizeVectorPair; j++)
		{
			if(j < pmergeMe.container2.size())
        		LeftVector2.push_back(pmergeMe.container2.at(j));
		}
		
        for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
		{
			if(j < pmergeMe.container2.size())
        		RightVector2.push_back(pmergeMe.container2.at(j));
		}
		pair.push_back(std::make_pair(LeftVector2, RightVector2));
	}

	// fill mainChain && Pend
	pmergeMe.mainChaine.clear();
	pmergeMe.pend.clear();
	for(size_t i=0; i<pair.size();i++)
	{
		if(i == 0)
		{
			pmergeMe.mainChaine.push_back(pair.at(i).first);
			pmergeMe.mainChaine.push_back(pair.at(i).second);
		}
		else
		{
			pmergeMe.mainChaine.push_back(pair.at(i).second);
			pmergeMe.pend.push_back(pair.at(i).first);
		}
	}
	if(pmergeMe.VectordyalXyata.size() > 0)
	{
		pmergeMe.pend.reserve(pmergeMe.pend.size() + pmergeMe.VectordyalXyata.size());
		for(size_t i=0; i<pmergeMe.VectordyalXyata.size(); i++)
			pmergeMe.pend.push_back(pmergeMe.VectordyalXyata.at(i));
		pmergeMe.VectordyalXyata.clear();
	}
	//using here lower_bound
	// for(size_t i=0; i<pmergeMe.pend.size();i++)
	// {
	// 	// if(pmergeMe.pend.at(i).back())
	// 	// {
	// 		// std::vector<std::vector<int> >::iterator it = std::lower_bound(pmergeMe.mainChaine.begin(), pmergeMe.mainChaine.end(), pmergeMe.pend.at(i), CompareLowerBound);
	// 		std::vector<std::vector<int> >::iterator it = std::upper_bound(pmergeMe.mainChaine.begin(), pmergeMe.mainChaine.end(), pmergeMe.pend.at(i), CompareLowerBound);
	// 		// if(pmergeMe.i == 2)
	// 		// exit(1);
	// 		if(it != pmergeMe.mainChaine.end())
	// 			pmergeMe.mainChaine.insert(it, pmergeMe.pend.at(i));
			
	// 	// }
	// }
	/*test*/
	int target;
	std::vector<std::vector<int> >::iterator it;
	size_t pos;
	size_t addedCount = 0;
	// size_t endPos;
	int i=0;
	for (it = pmergeMe.pend.begin(); it < pmergeMe.pend.end(); it++)
	{
		target = pmergeMe.pend.at(i).back();

		// endPos = i + addedCount;
		pos = binarySearch(pmergeMe.mainChaine, target, 0, pmergeMe.mainChaine.size());
		pmergeMe.mainChaine.insert(pmergeMe.mainChaine.begin() + pos, pmergeMe.pend.at(i));
		addedCount++;
		i++;
	}
	/*end test*/
	
	std::cout << "main Chain" << std::endl;
	for(size_t i=0; i<pmergeMe.mainChaine.size();i++)
	{
		for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
			std::cout << pmergeMe.mainChaine.at(i).at(j) << " ";
		std::cout << " | ";
	}
	std::cout << "\npend" << std::endl;
	for(size_t i=0; i<pmergeMe.pend.size();i++)
	{
		for(size_t j=0; j<pmergeMe.pend.at(i).size();j++)
			std::cout << pmergeMe.pend.at(i).at(j) << " ";
		std::cout << " | ";
	}
	std::cout << std::endl;
	//// empty lcontainer hna
	pmergeMe.container2.clear();
	//fill pmergeMe.container with mainChain
	for(size_t i=0; i<pmergeMe.mainChaine.size();i++)
	{
		for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
			pmergeMe.container2.push_back(pmergeMe.mainChaine.at(i).at(j));
	}
}
/*1 2 6 9 3 2 10 3 7*/
int main(int argc, char **argv)
{
	if (argc > 2)
	{
		PmergeMe pmergeMe;
		pmergeMe.i = 0;
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
		std::cout << "container after recursion :" << std::endl;
		for(size_t i=0; i<pmergeMe.container2.size(); i++)
			std::cout << pmergeMe.container2.at(i) << " " ;
		std::cout << std::endl;
		// std::cout << "container dyal xyata after recursion :" << std::endl;
		// for(size_t i=0; i<pmergeMe.VectordyalXyata.size(); i++)
		// 	std::cout << pmergeMe.VectordyalXyata.at(i) << " " ;
		// std::cout << std::endl;
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
	return 0;
}