/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/18 17:23:01 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int comp = 0;
bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
	comp++;
    return cmp1.back() <= cmp2.back();
}

void	PmergeMe::LastRecursion(size_t sizeVectorPair,  std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine)
{
	std::vector<int> tmp;
	sizeVectorPair /= 2;
	for(size_t i = 0; i < container.size(); i += sizeVectorPair)
	{
		for (size_t j = i; j < i + sizeVectorPair; j++)
		{
			if(j < container.size())
        		tmp.push_back(container.at(j));
		}
		mainChaine.push_back(tmp);
		tmp.clear();
	}
	if(VectordyalXyata.size() > 0)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
		mainChaine.insert(it, VectordyalXyata);
	}
	container.clear();
	for(size_t i=0; i<mainChaine.size();i++)
	{
		for(size_t j=0; j<mainChaine.at(i).size();j++)
			container.push_back(mainChaine.at(i).at(j));
	}
}

void	PmergeMe::ReverseRecursion(size_t sizeVectorPair, std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine, std::vector<std::vector<int> >& pend)
{
	pairR.clear();
	jacobSequence.clear();
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
	
	mainChaine.clear();
	pend.clear();
	for(size_t i=0; i<pairR.size();i++)
	{
		mainChaine.push_back(pairR.at(i).second);
		pend.push_back(pairR.at(i).first);

	}
	for(size_t i=2; i<pend.size(); i++)
	{
		int jac = jacobsthal(i);
		if(jac >= static_cast<int>(pend.size()))
		{
			jacobSequence.push_back(pend.size() - 1);
			break;
		}
		else
			jacobSequence.push_back(jacobsthal(i));
	}
	if(pend.size() >= 1)
		mainChaine.insert(mainChaine.begin(), pend.at(0));
	if(pend.size() >= 2)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.begin() + 2 , pend.at(1), CompareLowerBound);
		mainChaine.insert(it, pend.at(1));
	}

	//using here lower_bound
	int begin = 2;
	
	for(size_t i=0; i<jacobSequence.size(); i++)
	{

		int j = jacobSequence.at(i);
		int tmp = j;
		while(j >= begin)
		{
			std::vector<std::vector<int> >::iterator it;
			it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(j), CompareLowerBound);
			mainChaine.insert(it, pend.at(j));
			j--;
		}
		begin = tmp + 1;
	}
	if(VectordyalXyata.size() > 0)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
		mainChaine.insert(it, VectordyalXyata);
	}
	container.clear();
	for(size_t i=0; i<mainChaine.size();i++)
	{
		for(size_t j=0; j<mainChaine.at(i).size();j++)
			container.push_back(mainChaine.at(i).at(j));
	}
}

void	PmergeMe::MergeInsertSort(size_t sizeVectorPair)
{
	pair.clear();
	int xyata = container.size() % (sizeVectorPair * 2);
	std::vector<int> VectordyalXyata;
	std::vector<std::vector<int> > mainChaine;
	std::vector<std::vector<int> > pend;
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
			{
				comp++;
				pair.push_back(std::make_pair(RightVector, LeftVector));
			}
			else
        		pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			for(size_t l=container.size() - xyata; l<container.size(); l++)
				VectordyalXyata.push_back(container.at(l));
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
		LastRecursion(sizeVectorPair, VectordyalXyata, mainChaine);
		return;
	}
	MergeInsertSort(sizeVectorPair);
	ReverseRecursion(sizeVectorPair, VectordyalXyata, mainChaine, pend);
}
void	usingVector(PmergeMe& pmergeMe)
{
	pmergeMe.printBefore();
	pmergeMe.MergeInsertSort(1);
	pmergeMe.printAfter();
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		clock_t timeVec;
		clock_t timeList;
		try
		{
			PmergeMe pmergeMe;
			if(pmergeMe.fillContainer(argv) == 1)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			timeVec = clock();
			usingVector(pmergeMe);
			timeVec = clock() - timeVec;
			timeList = clock();
			// usingList(pmergeMe);
			timeList = clock() - timeList;
			//millesecond
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << static_cast<float>(timeVec) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << static_cast<float>(timeList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
		}
		catch(const std::exception& e)	
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;

	std::cout << "===>   " << comp << std::endl;
	return 0;
}
