/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:47:54 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/08 17:09:16 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void	step1(std::vector<int>& container)//group the elements of pair to two
// {
// 	int last_number = -1;
// 	// std::vector<std::pair<int, int> > pair;
// 	std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
// 	std::vector<int> LeftVector;
// 	std::vector<int> RightVector;
// 	if (container.size() % 2 == 1)
// 	{
// 		last_number = container.at(container.size() - 1);
// 		for(size_t i=0; i<container.size() - 1; i+=2)
// 		{
// 			LeftVector.push_back(container.at(i));
// 			RightVector.push_back(container.at(i + 1));
// 		}
// 		pair.push_back(std::make_pair(LeftVector, RightVector));
// 			// pair.push_back(std::make_pair(container.at(i), container.at(i + 1)));
// 	}
// 	else
// 	{
// 		for(size_t i=0; i<container.size(); i+=2)
// 		{
// 			LeftVector.push_back(container.at(i));
// 			RightVector.push_back(container.at(i + 1));
// 		}
// 		pair.push_back(std::make_pair(LeftVector, RightVector));
// 			// pair.push_back(std::make_pair(container.at(i), container.at(i + 1)));
// 	}
// 	for(size_t i=0; i<pair.size(); i++)
// 		std::cout << "[" << pair.at(i).first.at(i) << ", " << pair.at(i).second.at(i) << "]" << std::endl;
// 		// std::cout << "[" << pair.at(i).first << ", " << pair.at(i).second << "]" << std::endl;
// 	if(last_number != -1)
// 		std::cout << "[" << last_number << "]" << std::endl;
// }


// void	step1(std::vector<int>& container, size_t sizeVectorPair)//group the elements of pair to two
void	step1(PmergeMe& pmergeMe, size_t sizeVectorPair)
{
	// if (sizeVectorPair >= pmergeMe.container.size())
	// 	return ;
	// std::vector<int> VectordyalXyata;
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
    for (size_t i = 0; i < pmergeMe.container.size(); i += sizeVectorPair * 2) 
	{
        std::vector<int> LeftVector;
        std::vector<int> RightVector;
		int xyata = pmergeMe.container.size() % (sizeVectorPair * 2);
		
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
	if (pair.size() == 2)
		return ;
	sizeVectorPair++;
	step1(pmergeMe, sizeVectorPair);
	// for(size_t i = 0; i<container.size(); i++)
	// 	std::cout << container.at(i) << " ";
	// std::cout << std::endl;
	
	// int last_number = -1;
	// std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
	// for(size_t i=0; i<container.size(); i+=sizeVectorPair + 1)
	// {
	// 	std::vector<int> LeftVector;
	// 	std::vector<int> RightVector;
	// 	for(size_t i=0; i<sizeVectorPair; i++)
	// 		LeftVector.push_back(container.at(i));
	// 	for(size_t i=sizeVectorPair; i<sizeVectorPair * 2; i++)
	// 		RightVector.push_back(container.at(i));
	// 	if (LeftVector.at(LeftVector.size() -1) > RightVector.at(RightVector.size() -1))
	// 	{
	// 		int tmp = LeftVector.at(LeftVector.size() -1);
	// 		LeftVector.at(LeftVector.size() -1) = RightVector.at(RightVector.size() -1);
	// 		RightVector.at(RightVector.size() -1) = tmp;
	// 	}
	// 	pair.push_back(std::make_pair(LeftVector, RightVector));
	// }
	
	// if (container.size() % 2 == 1)
	// {
	// 	last_number = container.at(container.size() - 1);
	// 	for(size_t i=0; i<container.size() - 1; i+=2)
	// 	{
	// 		LeftVector.push_back(container.at(i));
	// 		RightVector.push_back(container.at(i + 1));
	// 	}
	// 	pair.push_back(std::make_pair(LeftVector, RightVector));
	// }
	// else
	// {
	// 	for(size_t i=0; i<container.size(); i+=2)
	// 	{
	// 		LeftVector.push_back(container.at(i));
	// 		RightVector.push_back(container.at(i + 1));
	// 	}
	// 	pair.push_back(std::make_pair(LeftVector, RightVector));
	// }
	// for(size_t i=0; i<pair.size(); i++)
	// 	std::cout << "[" << pair.at(i).first.at(0) << ", " << pair.at(i).second.at(0) << "]" << std::endl;
	// if(last_number != -1)
	// 	std::cout << "[" << last_number << "]" << std::endl;
}

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
		std::cout << "container after recursion :" << std::endl;
		for(size_t i=0; i<pmergeMe.container.size(); i++)
			std::cout << pmergeMe.container.at(i) << " " ;
		std::cout << std::endl;
		std::cout << "container dyal xyata after recursion :" << std::endl;
		for(size_t i=0; i<pmergeMe.VectordyalXyata.size(); i++)
			std::cout << pmergeMe.VectordyalXyata.at(i) << " " ;
		std::cout << std::endl;
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
	return 0;
}