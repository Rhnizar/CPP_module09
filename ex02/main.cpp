/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/14 20:52:20 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
    return cmp1.back() <= cmp2.back();
}

void	PmergeMe::LastRecursion()
{
	std::vector<int> tmp;
	for(size_t i=0; i<container.size(); i++)
	{
		tmp.push_back(container.at(i));
		mainChaine.push_back(tmp);
		tmp.clear();
	}
	for(size_t i=0; i<VectordyalXyata.size(); i++)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata.at(i), CompareLowerBound);
		mainChaine.insert(it, VectordyalXyata.at(i));
	}
}

void	PmergeMe::ReverseRecursion(size_t sizeVectorPair)
{
	pairR.clear();
	sizeVectorPair /= 2;
	for (size_t i = 0; i < container.size(); i += sizeVectorPair * 2)
	{
		std::vector<int> LeftVector2;
        std::vector<int> RightVector2;
	
		for (size_t j = i; j < i + sizeVectorPair; j++)
		{
			if(j < container.size())
        		LeftVector2.push_back(container.at(j));
		}
		
        for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
		{
			if(j < container.size())
        		RightVector2.push_back(container.at(j));
		}
		pairR.push_back(std::make_pair(LeftVector2, RightVector2));
	}
	// fill mainChaine && Pend
	mainChaine.clear();
	for(size_t i=0; i<pairR.size();i++)
	{
		if(i == 0)
		{
			mainChaine.push_back(pairR.at(i).first);
			mainChaine.push_back(pairR.at(i).second);
		}
		else
		{
			mainChaine.push_back(pairR.at(i).second);
			pend.push_back(pairR.at(i).first);
		}
	}
	if(VectordyalXyata.size() > 0)
	{
		for(size_t i=0; i<VectordyalXyata.size(); i++)
			pend.push_back(VectordyalXyata.at(i));
		VectordyalXyata.clear();
	}
	//using here lower_bound
	size_t len = pend.size();
	for(size_t i=0; i<len; i++)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(i), CompareLowerBound);
		mainChaine.insert(it, pend.at(i));
	}
	
	//  empty lcontainer hna
	container.clear();
	pend.clear();
	//fill pmergeMe.container with mainChain
	for(size_t i=0; i<mainChaine.size();i++)
	{
		for(size_t j=0; j<mainChaine.at(i).size();j++)
		{
			if(mainChaine.at(i).size() >= sizeVectorPair)
				container.push_back(mainChaine.at(i).at(j));
			else
			{
				pend.push_back(mainChaine.at(i));
				break;
			}
		}
	}
}

void	PmergeMe::MergeInsertSort(size_t sizeVectorPair)
{
	pair.clear();
	int xyata = container.size() % (sizeVectorPair * 2);

    for (size_t i = 0; i < container.size(); i += sizeVectorPair * 2) 
	{
        std::vector<int> LeftVector;
        std::vector<int> RightVector;
	
		if(i != container.size() - xyata)
		{
        	for (size_t j = i; j < i + sizeVectorPair; j++)
        	    LeftVector.push_back(container.at(j));
	
        	for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
        	    RightVector.push_back(container.at(j));

			
        	if (LeftVector.back() > RightVector.back())
				pair.push_back(std::make_pair(RightVector, LeftVector));
			else
        		pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			std::vector<int> xy;
			for(size_t l=container.size() - xyata; l<container.size(); l++)
				xy.push_back(container.at(l));
			VectordyalXyata.push_back(xy);
		}
    }
	
    // empty lcontainer hna
	container.clear();
	// fill lcontainer hna
	for (size_t i = 0; i < pair.size(); i++)
	{
		for(size_t j=0; j<pair.at(i).first.size(); j++)
			container.push_back(pair.at(i).first.at(j));
		for(size_t k=0; k<pair.at(i).second.size(); k++)
			container.push_back(pair.at(i).second.at(k));
	}
	
	sizeVectorPair *= 2;
	
	if (pair.size() <= 1)
	{
		LastRecursion();
		return;
	}
	
	MergeInsertSort(sizeVectorPair);
	ReverseRecursion(sizeVectorPair);
	// pair.clear();
	// sizeVectorPair /= 2;
	// for (size_t i = 0; i < container.size(); i += sizeVectorPair * 2)
	// {
	// 	std::vector<int> LeftVector2;
    //     std::vector<int> RightVector2;
	
	// 	for (size_t j = i; j < i + sizeVectorPair; j++)
	// 	{
	// 		if(j < container.size())
    //     		LeftVector2.push_back(container.at(j));
	// 	}
		
    //     for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
	// 	{
	// 		if(j < container.size())
    //     		RightVector2.push_back(container.at(j));
	// 	}
	// 	pair.push_back(std::make_pair(LeftVector2, RightVector2));
	// }

	// // // fill mainChaine && Pend
	// mainChaine.clear();
	// for(size_t i=0; i<pair.size();i++)
	// {
	// 	if(i == 0)
	// 	{
	// 		mainChaine.push_back(pair.at(i).first);
	// 		mainChaine.push_back(pair.at(i).second);
	// 	}
	// 	else
	// 	{
	// 		mainChaine.push_back(pair.at(i).second);
	// 		pend.push_back(pair.at(i).first);
	// 	}
	// }
	// if(VectordyalXyata.size() > 0)
	// {
	// 	for(size_t i=0; i<VectordyalXyata.size(); i++)
	// 		pend.push_back(VectordyalXyata.at(i));
	// 	VectordyalXyata.clear();
	// }
	// //using here lower_bound
	// size_t len = pend.size();
	// for(size_t i=0; i<len; i++)
	// {
	// 	std::vector<std::vector<int> >::iterator it;
	// 	it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(i), CompareLowerBound);
	// 	mainChaine.insert(it, pend.at(i));
	// }
	
	// // //// empty lcontainer hna
	// container.clear();
	// pend.clear();
	// //fill pmergeMe.container with mainChain

	// for(size_t i=0; i<mainChaine.size();i++)
	// {
	// 	for(size_t j=0; j<mainChaine.at(i).size();j++)
	// 	{
	// 		if(mainChaine.at(i).size() >= sizeVectorPair)
	// 			container.push_back(mainChaine.at(i).at(j));
	// 		else
	// 		{
	// 			pend.push_back(mainChaine.at(i));
	// 			break;
	// 		}
	// 	}
	// }

}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		try
		{
			PmergeMe pmergeMe;
			if(pmergeMe.fillContainer(argv) == 1)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			//print before
			pmergeMe.printBefore();
			pmergeMe.MergeInsertSort(1);
			// print container after recursion
			pmergeMe.printAfter();
		}
		catch(const std::exception& e)	
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
	return 0;
}
