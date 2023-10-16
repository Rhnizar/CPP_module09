/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:50:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/16 09:52:37 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // Include the <cstdlib> for strtod
#include <vector>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <list>


class PmergeMe
{
	public:
		std::vector<int> container;
		std::vector<std::vector<int> > VectordyalXyata;
		std::vector<std::vector<int> > mainChaine;
		std::vector<std::vector<int> > pend;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pairR;
		std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
		
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
};
static int comp = 0;
// Custom comparison function for sorting based on Jacobsthal sequence
bool CompareByJacobsthal(const std::pair<std::vector<int>, int>& a, const std::pair<std::vector<int>, int>& b) {
    
	// printf("yes\n");
	comp++;
	return a.second < b.second;
}

int	isInteger(std::string str)
{
	double res = strtod(str.c_str(), NULL);
	if(res > 2147483647)
		return 0;
	for(size_t i=0; i<str.length(); i++)
	{
		if (str[i] == '+' && i == 0)
			continue;
		if (std::isdigit(str.at(i)) == 0)
			return 0;
	}
	return 1;
}

int	PmergeMe::fillContainer(char **argv)
{
	int i = 1;
	numElements = 0;
	while (argv[i])
	{
		if(isInteger(argv[i]) == 0)
			return 1;
		numElements++;
		i++;
	}
	i = 1;
	container.reserve(numElements);
	while (argv[i])
	{
		container.push_back(strtod(argv[i], NULL));
		i++;
	}
	return 0;
}

void	PmergeMe::printBefore()
{
	std::cout << "Before: " << std::endl;
	for(size_t i=0; i<container.size(); i++)
		std::cout << container.at(i) << " ";
	std::cout << std::endl;
}

void	PmergeMe::printAfter()
{
	std::cout << "container after recursion :" << std::endl;
	for(size_t i=0; i<mainChaine.size(); i++)
	{
		for(size_t j=0; j<mainChaine.at(i).size(); j++)
			std::cout << mainChaine.at(i).at(j) << " " ;
	}
	std::cout << std::endl << std::endl;
}

/*jacobsthal*/

int		PmergeMe::jacobsthal(size_t n)
{
	return ((pow(2, n +1) + pow(-1, n)) / 3);
}





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
	/*heeere */
	for (size_t i = 0; i < pend.size(); i++)
        jacobSequence.push_back(jacobsthal(i));

    // Sort pend vectors based on Jacobsthal sequence
    std::vector<std::pair<std::vector<int>, int> > pendWithIndex;
    for (size_t i = 0; i < pend.size(); i++) {
        pendWithIndex.push_back(std::make_pair(pend[i], jacobSequence[i]));
    }

    // Sort pend vectors by Jacobsthal sequence (ascending order)
    std::sort(pendWithIndex.begin(), pendWithIndex.end(), CompareByJacobsthal);

    // Insert pend vectors into mainChaine based on Jacobsthal sequence
    for (const auto& pendPair : pendWithIndex) {
        std::vector<std::vector<int> >::iterator it;
        it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pendPair.first, CompareLowerBound);
        mainChaine.insert(it, pendPair.first);
    }
	// generateJacobIndex();
	// for(size_t i=0; i<pend.size(); i++)
	// 	jacobSequence.push_back(jacobsthal(i));
	// //using here lower_bound
	
	// for(size_t i=0; i<pend.size(); i++)
	// {
	// 	std::vector<std::vector<int> >::iterator it;
	// 	it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(i), CompareLowerBound);
	// 	mainChaine.insert(it, pend.at(i));
	// }
	
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


// #include <iostream>
// #include <cstdlib>
// #include <list> // Include <list> for using lists
// #include <ctime>
// #include <cmath>

// class PmergeMe
// {
// public:
//     std::list<int> container; // Change to use list<int>
//     std::list<std::list<int>> VectordyalXyata; // Change to list of lists
//     std::list<std::list<int>> mainChaine; // Change to list of lists
//     std::list<std::list<int>> pend; // Change to list of lists
//     std::list<std::pair<std::list<int>, std::list<int>> > pairR; // Change to list of pairs of lists
//     std::list<std::pair<std::list<int>, std::list<int>> > pair; // Change to list of pairs of lists

//     int numElements;

//     void printBefore();
//     void printAfter();
//     int fillContainer(char **argv);

//     void MergeInsertSort(size_t sizeVectorPair);
//     void LastRecursion();
//     void ReverseRecursion(size_t sizeVectorPair);

//     int jacobsthal(size_t index);

//     std::list<int> jacobSequence;
//     PmergeMe() {}
//     ~PmergeMe() {}
// };

// int isInteger(std::string str)
// {
//     double res = strtod(str.c_str(), NULL);
//     if (res > 2147483647)
//         return 0;
//     for (size_t i = 0; i < str.length(); i++)
//     {
//         if (str[i] == '+' && i == 0)
//             continue;
//         if (std::isdigit(str.at(i)) == 0)
//             return 0;
//     }
//     return 1;
// }

// int PmergeMe::fillContainer(char **argv)
// {
//     int i = 1;
//     numElements = 0;
//     while (argv[i])
//     {
//         if (isInteger(argv[i]) == 0)
//             return 1;
//         numElements++;
//         i++;
//     }
//     i = 1;
//     container.clear(); // Clear the list
//     while (argv[i])
//     {
//         container.push_back(strtod(argv[i], NULL)); // Use push_back for lists
//         i++;
//     }
//     return 0;
// }

// void PmergeMe::printBefore()
// {
//     std::cout << "Before: " << std::endl;
//     for (const auto &item : container)
//         std::cout << item << " ";
//     std::cout << std::endl;
// }

// void PmergeMe::printAfter()
// {
//     std::cout << "container after recursion :" << std::endl;
//     for (const auto &subList : mainChaine)
//     {
//         for (const auto &item : subList)
//             std::cout << item << " ";
//     }
//     std::cout << std::endl << std::endl;
// }

// int PmergeMe::jacobsthal(size_t n)
// {
//     return ((pow(2, n + 1) + pow(-1, n)) / 3);
// }

// static int comp = 0;
// bool CompareLowerBound(const std::list<int> &cmp1, const std::list<int> &cmp2)
// {
//     comp++;
//     return cmp1.back() <= cmp2.back();
// }

// void PmergeMe::LastRecursion()
// {
//     std::list<int> tmp;
//     for (const auto &item : container)
//     {
//         tmp.push_back(item);
//         mainChaine.push_back(tmp);
//         tmp.clear();
//     }
//     for (const auto &subList : VectordyalXyata)
//     {
//         auto it = std::lower_bound(mainChaine.begin(), mainChaine.end(), subList, CompareLowerBound);
//         mainChaine.insert(it, subList);
//     }
// }

// void PmergeMe::ReverseRecursion(size_t sizeVectorPair)
// {
//     pairR.clear();
//     jacobSequence.clear();
//     sizeVectorPair /= 2;
//     for (auto it = container.begin(); it != container.end(); std::advance(it, sizeVectorPair * 2))
//     {
//         std::list<int> LeftList2;
//         std::list<int> RightList2;

//         for (auto i = it; i != it; std::advance(i, 1))
//         {
//             if (i != container.end())
//                 LeftList2.push_back(*i);
//         }

//         for (auto i = it; i != it; std::advance(i, 1))
//         {
//             if (i != container.end())
//                 RightList2.push_back(*i);
//         }
//         pairR.push_back(std::make_pair(LeftList2, RightList2));
//     }

//     mainChaine.clear();
//     for (const auto &pair : pairR)
//     {
//         if (pairR.begin() == pair)
//         {
//             mainChaine.push_back(pair.first);
//             mainChaine.push_back(pair.second);
//         }
//         else
//         {
//             mainChaine.push_back(pair.second);
//             pend.push_back(pair.first);
//         }
//     }

//     if (!VectordyalXyata.empty())
//     {
//         for (const auto &subList : VectordyalXyata)
//             pend.push_back(subList);
//         VectordyalXyata.clear();
//     }

//     for (const auto &subList : pend)
//         jacobSequence.push_back(jacobsthal(jacobSequence.size()));

//     for (const auto &subList : pend)
//     {
//         auto it = std::lower_bound(mainChaine.begin(), mainChaine.end(), subList, CompareLowerBound);
//         mainChaine.insert(it, subList);
//     }

//     container.clear();
//     pend.clear();

//     for (const auto &subList : mainChaine)
//     {
//         for (const auto &item : subList)
//         {
//             if (subList.size() >= sizeVectorPair)
//                 container.push_back(item);
//             else
//             {
//                 pend.push_back(subList);
//                 break;
//             }
//         }
//     }
// }

// void PmergeMe::MergeInsertSort(size_t sizeVectorPair)
// {
//     pair.clear();
//     int xyata = std::distance(container.begin(), container.end()) % (sizeVectorPair * 2);

//     for (auto it = container.begin(); it != container.end(); std::advance(it, sizeVectorPair * 2))
//     {
//         std::list<int> LeftList;
//         std::list<int> RightList;

//         if (it != container.end())
//         {
//             for (auto i = it; i != it; std::advance(i, 1))
//                 LeftList.push_back(*i);

//             for (auto i = it; i != it; std::advance(i, 1))
//                 RightList.push_back(*i);

//             if (LeftList.back() > RightList.back())
//             {
//                 comp++;
//                 pair.push_back(std::make_pair(RightList, LeftList));
//             }
//             else
//                 pair.push_back(std::make_pair(LeftList, RightList));
//         }
//         else
//         {
//             std::list<int> xy;
//             for (auto l = std::next(container.begin(), std::distance(container.begin(), container.end()) - xyata);
//                  l != container.end();
//                  std::advance(l, 1))
//             {
//                 xy.push_back(*l);
//                 VectordyalXyata.push_back(xy);
//                 xy.clear();
//             }
//         }
//     }

//     container.clear();

//     for (const auto &pair : pair)
//     {
//         for (const auto &item : pair.first)
//             container.push_back(item);
//         for (const auto &item : pair.second)
//             container.push_back(item);
//     }

//     sizeVectorPair *= 2;

//     if (pair.size() <= 1)
//     {
//         LastRecursion();
//         return;
//     }

//     ReverseRecursion(sizeVectorPair);
// }

// void usingList(PmergeMe &pmergeMe)
// {
//     pmergeMe.printBefore();
//     pmergeMe.MergeInsertSort(1);
//     pmergeMe.printAfter();
// }

// int main(int argc, char **argv)
// {
//     if (argc >= 2)
//     {
//         clock_t timeList;
//         try
//         {
//             PmergeMe pmergeMe;
//             if (pmergeMe.fillContainer(argv) == 1)
//             {
//                 std::cout << "Error" << std::endl;
//                 return 0;
//             }
//             timeList = clock();
//             usingList(pmergeMe);
//             timeList = clock() - timeList;
//             std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << static_cast<float>(timeList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
//     }
//     else
//         std::cout << "Usage: " << argv[0] << " <numbers ...>   " << std::endl;

//     std::cout << "===> " << comp << std::endl;
//     return 0;
// }


 

//  #include <iostream>
// #include <cstdlib>
// #include <list>
// #include <ctime>
// #include <cmath>

// class PmergeMe
// {
// public:
//     std::list<int> container;
//     std::list<std::list<int> > VectordyalXyata;
//     std::list<std::list<int> > mainChaine;
//     std::list<std::list<int> > pend;
//     std::list<std::pair<std::list<int>, std::list<int> > > pairR;
//     std::list<std::pair<std::list<int>, std::list<int> > > pair;

//     int numElements;

//     void printBefore();
//     void printAfter();
//     int fillContainer(char **argv);

//     void MergeInsertSort(size_t sizeVectorPair);
//     void LastRecursion();
//     void ReverseRecursion(size_t sizeVectorPair);

//     int jacobsthal(size_t index);

//     std::list<int> jacobSequence;
//     PmergeMe() {}
//     ~PmergeMe() {}
// };

// int isInteger(std::string str)
// {
//     double res = strtod(str.c_str(), NULL);
//     if (res > 2147483647)
//         return 0;
//     for (size_t i = 0; i < str.length(); i++)
//     {
//         if (str[i] == '+' && i == 0)
//             continue;
//         if (std::isdigit(str.at(i)) == 0)
//             return 0;
//     }
//     return 1;
// }

// int PmergeMe::fillContainer(char **argv)
// {
//     int i = 1;
//     numElements = 0;
//     while (argv[i])
//     {
//         if (isInteger(argv[i]) == 0)
//             return 1;
//         numElements++;
//         i++;
//     }
//     i = 1;
//     container.clear();
//     while (argv[i])
//     {
//         container.push_back(strtod(argv[i], NULL));
//         i++;
//     }
//     return 0;
// }

// void PmergeMe::printBefore()
// {
//     std::cout << "Before: " << std::endl;
//     for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// void PmergeMe::printAfter()
// {
//     std::cout << "container after recursion :" << std::endl;
//     for (std::list<std::list<int> >::const_iterator it = mainChaine.begin(); it != mainChaine.end(); ++it)
//     {
//         for (std::list<int>::const_iterator inner_it = it->begin(); inner_it != it->end(); ++inner_it)
//             std::cout << *inner_it << " ";
//     }
//     std::cout << std::endl << std::endl;
// }

// int PmergeMe::jacobsthal(size_t n)
// {
//     return static_cast<int>((pow(2, n + 1) + pow(-1, n)) / 3);
// }

// static int comp = 0;
// bool CompareLowerBound(const std::list<int>& cmp1, const std::list<int>& cmp2)
// {
//     comp++;
//     return cmp1.back() <= cmp2.back();
// }

// void PmergeMe::LastRecursion()
// {
//     std::list<int> tmp;
//     for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it)
//     {
//         tmp.push_back(*it);
//         mainChaine.push_back(tmp);
//         tmp.clear();
//     }
//     for (std::list<std::list<int> >::const_iterator it = VectordyalXyata.begin(); it != VectordyalXyata.end(); ++it)
//     {
//         std::list<std::list<int> >::iterator it2 = std::lower_bound(mainChaine.begin(), mainChaine.end(), *it, CompareLowerBound);
//         mainChaine.insert(it2, *it);
//     }
// }

// void PmergeMe::ReverseRecursion(size_t sizeVectorPair)
// {
//     pairR.clear();
//     jacobSequence.clear();
//     sizeVectorPair /= 2;
//     for (std::list<int>::iterator it = container.begin(); it != container.end(); std::advance(it, sizeVectorPair * 2))
//     {
//         std::list<int> LeftList2;
//         std::list<int> RightList2;

//         for (std::list<int>::iterator i = it; i != it; std::advance(i, 1))
//         {
//             if (i != container.end())
//                 LeftList2.push_back(*i);
//         }

//         for (std::list<int>::iterator i = it; i != it; std::advance(i, 1))
//         {
//             if (i != container.end())
//                 RightList2.push_back(*i);
//         }
//         pairR.push_back(std::make_pair(LeftList2, RightList2));
//     }

//     mainChaine.clear();
//     for (std::list<std::pair<std::list<int>, std::list<int> > >::iterator it = pairR.begin(); it != pairR.end(); ++it)
//     {
//         if (it == pairR.begin())
//         {
//             mainChaine.push_back(it->first);
//             mainChaine.push_back(it->second);
//         }
//         else
//         {
//             mainChaine.push_back(it->second);
//             pend.push_back(it->first);
//         }
//     }

//     if (!VectordyalXyata.empty())
//     {
//         for (std::list<std::list<int> >::iterator it = VectordyalXyata.begin(); it != VectordyalXyata.end(); ++it)
//             pend.push_back(*it);
//         VectordyalXyata.clear();
//     }

//     for (std::list<std::list<int> >::iterator it = pend.begin(); it != pend.end(); ++it)
//         jacobSequence.push_back(jacobsthal(jacobSequence.size()));

//     for (std::list<std::list<int> >::iterator it = pend.begin(); it != pend.end(); ++it)
//     {
//         std::list<std::list<int> >::iterator it2 = std::lower_bound(mainChaine.begin(), mainChaine.end(), *it, CompareLowerBound);
//         mainChaine.insert(it2, *it);
//     }

//     container.clear();
//     pend.clear();

//     for (std::list<std::list<int> >::iterator it = mainChaine.begin(); it != mainChaine.end(); ++it)
//     {
//         for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
//         {
//             if (it->size() >= sizeVectorPair)
//                 container.push_back(*it2);
//             else
//             {
//                 pend.push_back(*it);
//                 break;
//             }
//         }
//     }
// }

// void PmergeMe::MergeInsertSort(size_t sizeVectorPair)
// {
//     pair.clear();
// 	int i = 0;
//     int xyata = std::distance(container.begin(), container.end()) % (sizeVectorPair * 2);
//     for (std::list<int>::iterator it = container.begin(); it != container.end(); std::advance(it, sizeVectorPair * 2))
//     {
//         std::list<int> LeftList;
//         std::list<int> RightList;

//         if (it != container.end())
//         {
//             for (std::list<int>::iterator i = it; i != it; std::advance(i, 1))
//                 LeftList.push_back(*i);

//             for (std::list<int>::iterator i = it; i != it; std::advance(i, 1))
//                 RightList.push_back(*i);

//             if (LeftList.back() > RightList.back())
//             {
//                 comp++;
//                 pair.push_back(std::make_pair(RightList, LeftList));
//             }
//             else
//                 pair.push_back(std::make_pair(LeftList, RightList));
//         }
//         else
//         {
//             std::list<int> xy;
//             for (std::list<int>::iterator it2 = std::next(container.begin(), std::distance(container.begin(), container.end()) - xyata);
//                 it2 != container.end();
//                 std::advance(it2, 1))
//             {
//                 xy.push_back(*it2);
//                 VectordyalXyata.push_back(xy);
//                 xy.clear();
//             }
//         }
// 		// if(i == 50)
// 		// 	exit(1);
// 		printf("here\n");
// 		i++;
//     }

//     container.clear();

//     for (std::list<std::pair<std::list<int>, std::list<int> > >::iterator it = pair.begin(); it != pair.end(); ++it)
//     {
//         for (std::list<int>::iterator it2 = it->first.begin(); it2 != it->first.end(); ++it2)
//             container.push_back(*it2);
//         for (std::list<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
//             container.push_back(*it2);
//     }
//     sizeVectorPair *= 2;

//     if (pair.size() <= 1)
//     {
//         LastRecursion();
//         return;
//     }
//     ReverseRecursion(sizeVectorPair);
// }

// void usingList(PmergeMe &pmergeMe)
// {
//     pmergeMe.printBefore();
//     pmergeMe.MergeInsertSort(1);
//     pmergeMe.printAfter();
// }

// int main(int argc, char **argv)
// {
//     if (argc >= 2)
//     {
//         clock_t timeList;
//         try
//         {
//             PmergeMe pmergeMe;
//             if (pmergeMe.fillContainer(argv) == 1)
//             {
//                 std::cout << "Error" << std::endl;
//                 return 0;
//             }
//             timeList = clock();
//             usingList(pmergeMe);
//             timeList = clock() - timeList;
//             std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << static_cast<float>(timeList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
//     }
//     else
//         std::cout << "Usage: " << argv[0] << " <numbers ...>   " << std::endl;

//     std::cout << "===> " << comp << std::endl;
//     return 0;
// }
