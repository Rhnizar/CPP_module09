/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/12 23:05:13 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// /*test*/
// 	int target;
// 	std::vector<std::vector<int> >::iterator it;
// 	size_t pos;
// 	size_t addedCount = 0;
// 	// size_t endPos;
// 	int i=0;
// 	for (it = pmergeMe.pend.begin(); it < pmergeMe.pend.end(); it++)
// 	{
// 		target = pmergeMe.pend.at(i).back();

// 		// endPos = i + addedCount;
// 		pos = binarySearch(pmergeMe.mainChaine, target, 0, pmergeMe.mainChaine.size());
// 		pmergeMe.mainChaine.insert(pmergeMe.mainChaine.begin() + pos, pmergeMe.pend.at(i));
// 		addedCount++;
// 		i++;
// 	}
// 	/*end test*/
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

bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
	// std::cout <<"rr ==> " << cmp2.back() << std::endl;
	// std::cout << "here : ";
	// for(size_t i=0; i<cmp1.size(); i++)
	// 	std::cout << cmp1.at(i) << " ";
	// std::cout << std::endl;
	// exit(1);
    return cmp1.back() <= cmp2.back();
    // return cmp1.back() > cmp2.back();
}

void	step1(PmergeMe& pmergeMe, size_t sizeVectorPair)
{
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
	int xyata = pmergeMe.container.size() % (sizeVectorPair * 2);

    for (size_t i = 0; i < pmergeMe.container.size(); i += sizeVectorPair * 2) 
	{
		std::cout << "for 1\n";
        std::vector<int> LeftVector;
        std::vector<int> RightVector;
	
		if(i != pmergeMe.container.size() - xyata)
		{
        	for (size_t j = i; j < i + sizeVectorPair; j++)
			{
				std::cout << "for 2\n";
        	    LeftVector.push_back(pmergeMe.container.at(j));
			}
	
        	for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
			{
				std::cout << "for 3\n";
        	    RightVector.push_back(pmergeMe.container.at(j));
			}
			
        	if (LeftVector.back() > RightVector.back())
				pair.push_back(std::make_pair(RightVector, LeftVector));
			else
        		pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			std::vector<int> xy;
			for(size_t l=pmergeMe.container.size() - xyata; l<pmergeMe.container.size(); l++)
			{
				std::cout << "for 4\n";
				xy.push_back(pmergeMe.container.at(l));
			}
			pmergeMe.VectordyalXyata.push_back(xy);
		}
    }
	
	// exit(1);
    // empty lcontainer hna
	pmergeMe.container.clear();
	// fill lcontainer hna
	for (size_t i = 0; i < pair.size(); i++)
	{
		std::cout << "for 5\n";
		for(size_t j=0; j<pair.at(i).first.size(); j++)
		{
			std::cout << "for 6\n";
			pmergeMe.container.push_back(pair.at(i).first.at(j));
		}
		for(size_t k=0; k<pair.at(i).second.size(); k++)
		{
			std::cout << "for 7\n";
			pmergeMe.container.push_back(pair.at(i).second.at(k));
		}
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
	for (size_t i = 0; i < pmergeMe.container.size(); i += sizeVectorPair * 2)
	{
		std::cout << "for 8\n";
		std::vector<int> LeftVector2;
        std::vector<int> RightVector2;
	
		for (size_t j = i; j < i + sizeVectorPair; j++)
		{
			std::cout << "for 9\n";
			if(j < pmergeMe.container.size())
        		LeftVector2.push_back(pmergeMe.container.at(j));
		}
		
        for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
		{
			std::cout << "for 10\n";
			if(j < pmergeMe.container.size())
        		RightVector2.push_back(pmergeMe.container.at(j));
		}
		pair.push_back(std::make_pair(LeftVector2, RightVector2));
	}

	// fill mainChain && Pend
	pmergeMe.mainChaine.clear();
	for(size_t i=0; i<pair.size();i++)
	{
		std::cout << "for 11\n";
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
	
	// if(pmergeMe.VectordyalXyata.empty() == 0)
	if(pmergeMe.VectordyalXyata.size() > 0)
	{
		for(size_t i=0; i<pmergeMe.VectordyalXyata.size(); i++)
		{
			std::cout << "for 12\n";
			pmergeMe.pend.push_back(pmergeMe.VectordyalXyata.at(i));
		}
		pmergeMe.VectordyalXyata.clear();
	}
	//print mainchaine and pend
	// std::cout << "main Chain" << std::endl;
	// for(size_t i=0; i<pmergeMe.mainChaine.size();i++)
	// {
	// 	for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
	// 		std::cout << pmergeMe.mainChaine.at(i).at(j) << " ";
	// 	std::cout << " | ";
	// }
	// std::cout << "\npend" << std::endl;
	// for(size_t i=0; i<pmergeMe.pend.size();i++)
	// {
	// 	for(size_t j=0; j<pmergeMe.pend.at(i).size();j++)
	// 		std::cout << pmergeMe.pend.at(i).at(j) << " ";
	// 	std::cout << " | ";
	// }
	std::cout << std::endl;
	//using here lower_bound
	size_t len = pmergeMe.pend.size();
	for(size_t i=0; i<len; i++)
	{
		std::cout << "for 13\n";
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(pmergeMe.mainChaine.begin(), pmergeMe.mainChaine.end(), pmergeMe.pend.at(i), CompareLowerBound);
		// if(pmergeMe.i == 2 && i == 2)
		// exit(1);
		pmergeMe.mainChaine.insert(it, pmergeMe.pend.at(i));

		// pmergeMe.mainChaine.push_back(pmergeMe.pend.at(i));
		// int pos = binarySearch(pmergeMe.mainChaine, pmergeMe.pend.at(i).back(), 0, pmergeMe.mainChaine.size());
		// pmergeMe.mainChaine.insert(pmergeMe.mainChaine.begin() + pos, pmergeMe.pend.at(i));
	}
	
	// std::cout << "last main Chain" << std::endl;
	// for(size_t i=0; i<pmergeMe.mainChaine.size();i++)
	// {
	// 	for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
	// 		std::cout << pmergeMe.mainChaine.at(i).at(j) << " ";
	// 	std::cout << " | ";
	// }
	// std::cout << std::endl;
	//// empty lcontainer hna
	pmergeMe.container.clear();
	pmergeMe.pend.clear();
	//fill pmergeMe.container with mainChain
	size_t len2 = pmergeMe.mainChaine.size();
	for(size_t i=0; i<len2;i++)
	{
		std::cout << "for 14\n";
		for(size_t j=0; j<pmergeMe.mainChaine.at(i).size();j++)
		{
			std::cout << "for 15\n";
			if(pmergeMe.mainChaine.at(i).size() == sizeVectorPair)
				pmergeMe.container.push_back(pmergeMe.mainChaine.at(i).at(j));
			else
				pmergeMe.pend.push_back(pmergeMe.mainChaine.at(i));
		}
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
		for(size_t i=0; i<pmergeMe.container.size(); i++)
			std::cout << pmergeMe.container.at(i) << " " ;
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