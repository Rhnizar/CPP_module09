/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/21 00:21:40 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int comp = 0;
static int compList = 0;
bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
	comp++;
    return cmp1.back() <= cmp2.back();
}
bool CompareLowerBound_List(const std::list<int>& cmp1, const std::list<int>& cmp2) 
{
	compList++;
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

			comp++;
        	if (LeftVector.back() > RightVector.back())
				pair.push_back(std::make_pair(RightVector, LeftVector));
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

/* here using list in function MergeInsertSort*/

void PmergeMe::MergeInsertSort_For_List(size_t sizeListPair)
{
    Lpair.clear();
    int xyata = ListContainer.size() % (sizeListPair * 2);
    std::list<int> ListDyalXyata;
    std::list<std::list<int> > mainChaine;
    std::list<std::list<int> > pend;

	std::list<int>::iterator ListIter = ListContainer.begin();
	std::advance(ListIter, ListContainer.size() - xyata);
	
	std::list<int>::iterator it = ListContainer.begin();
	// size_t step = sizeListPair * 2;
    while (it != ListContainer.end())
	{
        std::list<int> LeftList;
        std::list<int> RightList;
		if(it != ListIter)
        {
            for (size_t j = 0; j < sizeListPair; j++)
            {
                LeftList.push_back(*it);
                std::advance(it, 1);
            }

            for (size_t j = 0; j < sizeListPair; j++)
            {
                RightList.push_back(*it);
                std::advance(it, 1);
            }
			compList++;
            if (LeftList.back() > RightList.back())
                Lpair.push_back(std::make_pair(RightList, LeftList));
            else
                Lpair.push_back(std::make_pair(LeftList, RightList));
        }
        else
        {
            for (; it != ListContainer.end(); ++it)
                ListDyalXyata.push_back(*it);
        }
    }
	
    // Empty the list ListContainer
    ListContainer.clear();
    // Fill the list ListContainer
	std::list<std::pair<std::list<int>, std::list<int> > >::iterator ite;
	for (ite = Lpair.begin(); ite != Lpair.end(); ite++)
	{
    	const std::list<int>& first = ite->first;
    	const std::list<int>& second = ite->second;
    	ListContainer.insert(ListContainer.end(), first.begin(), first.end());
    	ListContainer.insert(ListContainer.end(), second.begin(), second.end());
	}


    sizeListPair *= 2;

    if (Lpair.size() <= 1)
    {
        LastRecursion_For_List(sizeListPair, ListDyalXyata, mainChaine);
        return;
    }
    MergeInsertSort_For_List(sizeListPair);
    ReverseRecursion_For_List(sizeListPair, ListDyalXyata, mainChaine, pend);
}

/* here using last recursion for list*/

void	PmergeMe::LastRecursion_For_List(size_t sizeListPair,  std::list<int>& ListDyalXyata, std::list<std::list<int> >& mainChaine)
{
	std::list<int> tmp;
	sizeListPair /= 2;
	std::list<int>::iterator DistanceIter;
	
	std::list<int>::iterator it = ListContainer.begin();
	while(it != ListContainer.end())
    {
		DistanceIter = it;
		std::advance(DistanceIter, sizeListPair);
		while(it != DistanceIter)
		{
			tmp.push_back(*it);
			it++;
		}
		mainChaine.push_back(tmp);
		tmp.clear();
	}
	if(ListDyalXyata.size() > 0)
	{
		std::list<std::list<int> >::iterator listit;
		listit = std::lower_bound(mainChaine.begin(), mainChaine.end(), ListDyalXyata, CompareLowerBound_List);
		mainChaine.insert(listit, ListDyalXyata);
	}
	ListContainer.clear();
	std::list<std::list<int> >::iterator mainIte;
	for(mainIte = mainChaine.begin(); mainIte != mainChaine.end();mainIte++)
	{
		const std::list<int>& ListTmp = *mainIte;
		ListContainer.insert(ListContainer.end(), ListTmp.begin(), ListTmp.end());
	}
}

// /* here using Reverse recursion for list*/
void PmergeMe::ReverseRecursion_For_List(size_t sizeListPair, std::list<int>& ListDyalXyata, std::list<std::list<int> >& mainChaine, std::list<std::list<int> >& pend)
{
    LpairR.clear();
    jacobSequence.clear();
    sizeListPair /= 2;
    std::list<int>::iterator it = ListContainer.begin();
    while (it != ListContainer.end())
	{
        std::list<int> LeftList2;
        std::list<int> RightList2;
        for (size_t j = 0; j < sizeListPair; j++)
        {
            if (it != ListContainer.end())
            {
                LeftList2.push_back(*it);
                std::advance(it, 1);
            }
        }
        for (size_t j = 0; j < sizeListPair; j++)
        {
            if (it != ListContainer.end())
            {
                RightList2.push_back(*it);
                std::advance(it, 1);
            }
        }
        LpairR.push_back(std::make_pair(LeftList2, RightList2));
    }
    mainChaine.clear();
    pend.clear();
	std::list<std::pair<std::list<int>, std::list<int> > >::iterator Liter;
	for (Liter = LpairR.begin(); Liter != LpairR.end(); Liter++)
    {
        mainChaine.push_back((*Liter).second);
        pend.push_back((*Liter).first);
    }
	
    for (size_t i = 2; i < pend.size(); i++)
    {
        int jac = jacobsthal(i);
        if (jac >= static_cast<int>(pend.size()))
        {
            jacobSequence.push_back(pend.size() - 1);
            break;
        }
        else
            jacobSequence.push_back(jacobsthal(i));
    }
    if (!pend.empty())
        mainChaine.insert(mainChaine.begin(), pend.front());
	
    if (pend.size() >= 2)
    {
		std::list<std::list<int> >::iterator penIter = pend.begin();
		std::advance(penIter, 1);
		std::list<std::list<int> >::iterator nextit = mainChaine.begin();
		std::advance(nextit, 2);
        // std::list<std::list<int> >::iterator listit = std::lower_bound(mainChaine.begin(), std::next(mainChaine.begin(), 2), *penIter, CompareLowerBound_List);
        std::list<std::list<int> >::iterator listit = std::lower_bound(mainChaine.begin(), nextit, *penIter, CompareLowerBound_List);
        
		mainChaine.insert(listit, *penIter);
    }
    int begin = 2; 
    for (size_t i = 0; i < jacobSequence.size(); i++)
    {
        int j = jacobSequence.at(i);
        int tmp = j;
        while (j >= begin)
        {
			std::list<std::list<int> >::iterator listit = mainChaine.begin();
			std::list<std::list<int> >::iterator it2 = pend.begin();
			std::advance(it2, j);;
			listit = std::lower_bound(mainChaine.begin(), mainChaine.end(), *it2, CompareLowerBound_List);
            mainChaine.insert(listit, *it2);
            j--;
        }
        begin = tmp + 1;
    }

    if (!ListDyalXyata.empty())
    {
        std::list<std::list<int> >::iterator listit  = std::lower_bound(mainChaine.begin(), mainChaine.end(), ListDyalXyata, CompareLowerBound_List);
        mainChaine.insert(listit, ListDyalXyata);
    }
    ListContainer.clear(); 
	std::list<std::list<int> >::iterator ite;
	for (ite = mainChaine.begin(); ite != mainChaine.end(); ite++)
	{
    	const std::list<int>& first = *ite;
		ListContainer.insert(ListContainer.end(), first.begin(), first.end());
	}
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
			pmergeMe.i = -1;
			if(pmergeMe.fillContainer(argv) == 1)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			timeVec = clock();
			usingVector(pmergeMe);
			timeVec = clock() - timeVec;
			timeList = clock();
			// pmergeMe.printListBefore();
			pmergeMe.MergeInsertSort_For_List(1);
			// pmergeMe.printListAfter();
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

	// std::cout << "comparison in vector ===>   " << comp << std::endl;
	// std::cout << "comparison in list ===>   " << compList << std::endl;
	return 0;
}
