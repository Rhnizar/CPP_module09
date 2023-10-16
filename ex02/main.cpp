/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/16 22:46:25 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int comp = 0;
bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
	comp++;
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
	//fill container with iterators 
	Vecit.clear();
	std::vector<std::vector<int> >::iterator ite;
	for(ite = mainChaine.begin(); ite != mainChaine.end(); ite++)
	{
		Vecit.push_back(ite);
	}
	//check mainChaine container
	// for(size_t i=0; i<Vecit.size(); i++)
	// {
	// 	std::vector<int> &tmpVec = *(Vecit.at(i));
	// 	for(size_t i=0; i<tmpVec.size(); i++)
	// 		std::cout << tmpVec.at(i) << " ";
	// 	std::cout << "\n-----------------  -------------------\n";
	// }
	// std::cout << std::endl;
	// exit(1);
	// generateJacobIndex();
	
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
	//using here lower_bound
	int begin = 0;
	for(size_t i=0; i<jacobSequence.size(); i++)
	{
		int j = jacobSequence.at(i) - 1;
		int tmp = j + 1;
		while(j >= begin)
		{
			if(j >= (int)pend.size())
				j = pend.size() - 1;
			int tmpJ = j;
			std::vector<std::vector<int> >::iterator it;
			for(size_t i=tmpJ; i<Vecit.size(); i++)
			{
				Vecit.at(i)++;
			}
			it = std::lower_bound(mainChaine.begin(), Vecit.at(tmpJ) , pend.at(j), CompareLowerBound);
			// it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(j), CompareLowerBound);
		
			mainChaine.insert(it, pend.at(j));
			pend.erase(pend.begin() + j);
			j--;
		}
		begin = tmp;
	}
	for(size_t i=0; i<pend.size(); i++)
	{
		std::vector<std::vector<int> >::iterator it;
		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(i), CompareLowerBound);
		mainChaine.insert(it, pend.at(i));
	}
	pend.clear();
	
	//  empty lcontainer hna
	container.clear();
	// pend.clear();
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
			{
				comp++;
				pair.push_back(std::make_pair(RightVector, LeftVector));
			}
			else
        		pair.push_back(std::make_pair(LeftVector, RightVector));
		}
		else
		{
			std::vector<int> xy;
			for(size_t l=container.size() - xyata; l<container.size(); l++)
			{
				xy.push_back(container.at(l));
				VectordyalXyata.push_back(xy);
				xy.clear();
			}
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
		// std::cout << "in last recursion \n";
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
		// std::cout << "xyta \n";
		// for (size_t i = 0; i < VectordyalXyata.size(); i++) 
		// {
		// 	for (size_t j = 0; j < VectordyalXyata.at(i).size(); j++)
		// 		std::cout << VectordyalXyata.at(i).at(j) << " " ;
		// }
		// std::cout << std::endl;
		// exit(1);
		LastRecursion();
		return;
	}
	MergeInsertSort(sizeVectorPair);
	ReverseRecursion(sizeVectorPair);
}
void	usingVector(PmergeMe& pmergeMe)
{
	//print before
	pmergeMe.printBefore();
	pmergeMe.MergeInsertSort(1);
	// print container after recursion
	pmergeMe.printAfter();
}

// void	usingList(PmergeMe& pmergeMe)
// {
// 	std::list<int>::iterator it;
// 	for(it =pmergeMe.containerList.begin(); it!=pmergeMe.containerList.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

// void	PmergeMe::usingList(size_t sizeListPair)
// {
// 	Lpair.clear();
// 	int xyata = containerList.size() % (sizeListPair * 2);

//     for (size_t i = 0; i < containerList.size(); i += sizeListPair * 2) 
// 	{
//         std::list<int> LeftVector;
//         std::list<int> RightVector;
	
// 		if(i != containerList.size() - xyata)
// 		{
//         	// for (size_t j = i; j < i + sizeListPair; j++)
// 			std::list<int>::iterator it;
// 			for (it = containerList.begin(); it != it + sizeListPair; ++it)
//         	    LeftVector.push_back(*it);
	
//         	for (; it != containerList.end(); ++it)
//         	    RightVector.push_back(*it);

//         	if (LeftVector.back() > RightVector.back())
// 			{
// 				comp++;
// 				Lpair.push_back(std::make_pair(RightVector, LeftVector));
// 			}
// 			else
//         		Lpair.push_back(std::make_pair(LeftVector, RightVector));
// 		}
// 		else
// 		{
// 			std::vector<int> xy;
// 			for(size_t l=containerList.size() - xyata; l<containerList.size(); l++)
// 			{
// 				xy.push_back(containerList.at(l));
// 				listdyalXyata.push_back(xy);
// 				xy.clear();
// 			}
// 		}
//     }
	
//     // empty lcontainerList hna
// 	containerList.clear();
// 	// fill lcontainerList hna
// 	for (size_t i = 0; i < Lpair.size(); i++)
// 	{
// 		for(size_t j=0; j<Lpair.at(i).first.size(); j++)
// 			containerList.push_back(Lpair.at(i).first.at(j));
// 		for(size_t k=0; k<Lpair.at(i).second.size(); k++)
// 			containerList.push_back(Lpair.at(i).second.at(k));
// 	}
// 	sizeListPair *= 2;
// 	if (Lpair.size() <= 1)
// 	{
// 		// LastRecursion();
// 		return;
// 	}
// 	usingList(sizeListPair);
// 	// ReverseRecursion(sizeListPair);
// }

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


//11 6 3 66 28 80 65 42 71 88 67 33 5 58 28 78 94 43 18 95 80 





            //   94 94 94 94 95

            // 5 58  78 94 43 18 95 