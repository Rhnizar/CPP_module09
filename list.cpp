
// #include <iostream>
// #include <cstdlib> // Include the <cstdlib> for strtod
// #include <vector>
// #include <unistd.h>
// #include <ctime>
// #include <cmath>
// #include <list>
// #include <algorithm>
// class PmergeMe
// {
// 	public:
// 		std::vector<int> container;
// 		std::vector<std::pair<std::vector<int>, std::vector<int> > > pairR;
// 		std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;	
// 		int		numElements;
// 		void	printBefore();
// 		void	printAfter();
// 		int		fillContainer(char **argv);	
// 		void	MergeInsertSort(size_t sizeVectorPair);
// 		void	ReverseRecursion(size_t sizeVectorPair, std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine, std::vector<std::vector<int> >& pend);
// 		void	LastRecursion(size_t sizeVectorPair,  std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine);
// 		/*jacobsthal*/
// 		// void	generateJacobIndex();
// 		int		jacobsthal(size_t index);
// 		std::vector<int> jacobSequence;
// 		PmergeMe(){}
// 		~PmergeMe(){}
// };
// int		PmergeMe::jacobsthal(size_t n)
// {
// 	return ((pow(2, n +1) + pow(-1, n)) / 3);
// }
// void	PmergeMe::printBefore()
// {
// 	std::cout << "Before: " << std::endl;
// 	for(size_t i=0; i<container.size(); i++)
// 		std::cout << container.at(i) << " ";
// 	std::cout << std::endl;
// }
// void	PmergeMe::printAfter()
// {
// 	std::cout << "\ncontainer after recursion :" << std::endl;
// 	for(size_t i=0; i<container.size(); i++)
// 		std::cout << container.at(i) << " ";
// 	std::cout << std::endl;
// }
// int	isInteger(std::string str)
// {
// 	double res = strtod(str.c_str(), NULL);
// 	if(res > 2147483647)
// 		return 0;
// 	for(size_t i=0; i<str.length(); i++)
// 	{
// 		if (str[i] == '+' && i == 0)
// 			continue;
// 		if (std::isdigit(str.at(i)) == 0)
// 			return 0;
// 	}
// 	return 1;
// }
// int	PmergeMe::fillContainer(char **argv)
// {
// 	int i = 1;
// 	numElements = 0;
// 	while (argv[i])
// 	{
// 		if(isInteger(argv[i]) == 0)
// 			return 1;
// 		numElements++;
// 		i++;
// 	}
// 	i = 1;
// 	container.reserve(numElements);
// 	while (argv[i])
// 	{
// 		container.push_back(strtod(argv[i], NULL));
// 		i++;
// 	}
// 	return 0;
// }
// bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
// {
//     return cmp1.back() <= cmp2.back();
// }
// void	PmergeMe::LastRecursion(size_t sizeVectorPair,  std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine)
// {
// 	std::vector<int> tmp;
// 	sizeVectorPair /= 2;
// 	for(size_t i = 0; i < container.size(); i += sizeVectorPair)
// 	{
// 		for (size_t j = i; j < i + sizeVectorPair; j++)
// 		{
// 			if(j < container.size())
//         		tmp.push_back(container.at(j));
// 		}
// 		mainChaine.push_back(tmp);
// 		tmp.clear();
// 	}
// 	if(VectordyalXyata.size() > 0)
// 	{
// 		std::vector<std::vector<int> >::iterator it;
// 		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
// 		mainChaine.insert(it, VectordyalXyata);
// 	}
// 	container.clear();
// 	for(size_t i=0; i<mainChaine.size();i++)
// 	{
// 		for(size_t j=0; j<mainChaine.at(i).size();j++)
// 			container.push_back(mainChaine.at(i).at(j));
// 	}
// }
// void	PmergeMe::ReverseRecursion(size_t sizeVectorPair, std::vector<int>& VectordyalXyata, std::vector<std::vector<int> >& mainChaine, std::vector<std::vector<int> >& pend)
// {
// 	pairR.clear();
// 	jacobSequence.clear();
// 	sizeVectorPair /= 2;
// 	for (size_t i = 0; i < container.size(); i += sizeVectorPair * 2)
// 	{
// 		std::vector<int> LeftVector2;
//         std::vector<int> RightVector2;
// 		for (size_t j = i; j < i + sizeVectorPair; j++)
// 		{
// 			if(j < container.size())
//         		LeftVector2.push_back(container.at(j));
// 		}	
//         for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
// 		{
// 			if(j < container.size())
//         		RightVector2.push_back(container.at(j));
// 		}
// 		pairR.push_back(std::make_pair(LeftVector2, RightVector2));
// 	}
// 	mainChaine.clear();
// 	pend.clear();
// 	for(size_t i=0; i<pairR.size();i++)
// 	{
// 		mainChaine.push_back(pairR.at(i).second);
// 		pend.push_back(pairR.at(i).first);
// 	}
// 	for(size_t i=2; i<pend.size(); i++)
// 	{
// 		int jac = jacobsthal(i);
// 		if(jac >= static_cast<int>(pend.size()))
// 		{
// 			jacobSequence.push_back(pend.size() - 1);
// 			break;
// 		}
// 		else
// 			jacobSequence.push_back(jacobsthal(i));
// 	}
// 	if(pend.size() >= 1)
// 		mainChaine.insert(mainChaine.begin(), pend.at(0));
// 	if(pend.size() >= 2)
// 	{
// 		std::vector<std::vector<int> >::iterator it;
// 		it = std::lower_bound(mainChaine.begin(), mainChaine.begin() + 2 , pend.at(1), CompareLowerBound);
// 		mainChaine.insert(it, pend.at(1));
// 	}
// 	//using here lower_bound
// 	int begin = 2;	
// 	for(size_t i=0; i<jacobSequence.size(); i++)
// 	{
// 		int j = jacobSequence.at(i);
// 		int tmp = j;
// 		while(j >= begin)
// 		{
// 			std::vector<std::vector<int> >::iterator it;
// 			it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend.at(j), CompareLowerBound);
// 			mainChaine.insert(it, pend.at(j));
// 			j--;
// 		}
// 		begin = tmp + 1;
// 	}
// 	if(VectordyalXyata.size() > 0)
// 	{
// 		std::vector<std::vector<int> >::iterator it;
// 		it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
// 		mainChaine.insert(it, VectordyalXyata);
// 	}
// 	container.clear();
// 	for(size_t i=0; i<mainChaine.size();i++)
// 	{
// 		for(size_t j=0; j<mainChaine.at(i).size();j++)
// 			container.push_back(mainChaine.at(i).at(j));
// 	}
// }
// void	PmergeMe::MergeInsertSort(size_t sizeVectorPair)
// {
// 	pair.clear();
// 	int xyata = container.size() % (sizeVectorPair * 2);
// 	std::vector<int> VectordyalXyata;
// 	std::vector<std::vector<int> > mainChaine;
// 	std::vector<std::vector<int> > pend;
//     for (size_t i = 0; i < container.size(); i += sizeVectorPair * 2) 
// 	{
//         std::vector<int> LeftVector;
//         std::vector<int> RightVector;
// 		if(i != container.size() - xyata)
// 		{
//         	for (size_t j = i; j < i + sizeVectorPair; j++)
//         	    LeftVector.push_back(container.at(j));
//         	for (size_t j = i + sizeVectorPair; j < i + sizeVectorPair * 2; j++)
//         	    RightVector.push_back(container.at(j));
//         	if (LeftVector.back() > RightVector.back())
// 			{			
// 				pair.push_back(std::make_pair(RightVector, LeftVector));
// 			}
// 			else
//         		pair.push_back(std::make_pair(LeftVector, RightVector));
// 		}
// 		else
// 		{
// 			for(size_t l=container.size() - xyata; l<container.size(); l++)
// 				VectordyalXyata.push_back(container.at(l));
// 		}
//     }
//     // empty lcontainer hna
// 	container.clear();
// 	// fill lcontainer hna
// 	for (size_t i = 0; i < pair.size(); i++)
// 	{
// 		for(size_t j=0; j<pair.at(i).first.size(); j++)
// 			container.push_back(pair.at(i).first.at(j));
// 		for(size_t k=0; k<pair.at(i).second.size(); k++)
// 			container.push_back(pair.at(i).second.at(k));
// 	}
// 	sizeVectorPair *= 2;
// 	if (pair.size() <= 1)
// 	{
// 		LastRecursion(sizeVectorPair, VectordyalXyata, mainChaine);
// 		return;
// 	}
// 	MergeInsertSort(sizeVectorPair);
// 	ReverseRecursion(sizeVectorPair, VectordyalXyata, mainChaine, pend);
// }
// void	usingVector(PmergeMe& pmergeMe)
// {
// 	pmergeMe.printBefore();
// 	pmergeMe.MergeInsertSort(1);
// 	pmergeMe.printAfter();
// }
// int main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		clock_t timeVec;
// 		clock_t timeList;
// 		try
// 		{
// 			PmergeMe pmergeMe;
// 			if(pmergeMe.fillContainer(argv) == 1)
// 			{
// 				std::cout << "Error" << std::endl;
// 				return 0;
// 			}
// 			timeVec = clock();
// 			usingVector(pmergeMe);
// 			timeVec = clock() - timeVec;
// 			timeList = clock();
// 			timeList = clock() - timeList;
// 			std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << static_cast<float>(timeVec) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
// 			std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << static_cast<float>(timeList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
// 		}
// 		catch(const std::exception& e)	
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	else
// 		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
// 	return 0;
// }




#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
#include <ctime>

class PmergeMe
{
public:
	void printBefore()
	{
		std::cout << "Before: " << std::endl;
		for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	
	void printAfter()
	{
		std::cout << "After: " << std::endl;
		for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	
	int fillContainer(char** argv)
	{
		for (int i = 1; argv[i]; ++i)
		{
			try
			{
				container.push_back(std::stoi(argv[i]));
			}
			catch (const std::exception& e)
			{
				std::cerr << "Invalid argument: " << argv[i] << std::endl;
				return 1;
			}
		}
		return 0;
	}
	
	void MergeInsertSort(size_t sizeVectorPair)
	{
		
		pair.clear();
		// int xyata = container.size() % (sizeVectorPair * 2);
		std::list<int> VectordyalXyata;
		std::list<std::list<int> > mainChaine;
		std::list<std::list<int> > pend;
		int incre = 0;
		// std::list<int>::iterator it = container.begin();
		// while (it != container.end())
		// {
		// 	std::advance(it, (sizeVectorPair * 2));
		// }
		std::list<int>::iterator it = container.begin();
		size_t step = sizeVectorPair * 2;

		while (it != container.end())
		{
    		// Check if advancing by step would go beyond the end
    		if (std::distance(it, container.end()) < static_cast<int>(step))
			{
    		    // Adjust the step to reach the end of the list
    		    step = std::distance(it, container.end());
    		}
			std::cout << *it << " " ;
			std::advance(it, step);
		}
		exit(1);
		// 	// std::cout << sizeVectorPair * 2 << "\n";
		// 	// it++;
		// 	// if(sizeVectorPair * 2 < container.size() -1)
		// 		std::advance(it, (sizeVectorPair * 2) < container.size() ? (sizeVectorPair * 2) : (sizeVectorPair * 2 - 1));
		// }
		exit(1);
		for (std::list<int>::iterator it = container.begin(); it != container.end(); std::advance(it, sizeVectorPair * 2))
		{
			std::list<int> LeftVector;
			std::list<int> RightVector;
			
			// if (it != container.end() && std::distance(it, container.end()) >= (int)sizeVectorPair * 2)
			// {
			// 	// for (size_t j = 0; j < sizeVectorPair; ++j)
			// 	// {
			// 	// 	if (it != container.end())
			// 	// 	{
			// 	// 		LeftVector.push_back(*it);
			// 	// 		it++;
			// 	// 	}
			// 	// }
				
			// 	// for (size_t j = 0; j < sizeVectorPair; ++j)
			// 	// {
			// 	// 	if (it != container.end())
			// 	// 	{
			// 	// 		RightVector.push_back(*it);
			// 	// 		it++;
			// 	// 	}
			// 	// }
				
			// 	if (LeftVector.back() > RightVector.back())
			// 	{
			// 		pair.push_back(std::make_pair(RightVector, LeftVector));
			// 	}
			// 	else
			// 		pair.push_back(std::make_pair(LeftVector, RightVector));
			// }
			// else
			// {
			// 	while(it != container.end())
			// 	{
			// 		VectordyalXyata.push_back(*it);
			// 		++it;
			// 	}
			// }
			// if (incre == 1000000)
			// 	exit(1);
			incre++;
		}
		// Empty container here
		container.clear();
		// Fill container here
		for (std::list<std::pair<std::list<int>, std::list<int> > >::iterator it = pair.begin(); it != pair.end(); ++it)
		{
			for (std::list<int>::iterator subIt = it->first.begin(); subIt != it->first.end(); ++subIt)
				container.push_back(*subIt);
			
			for (std::list<int>::iterator subIt = it->second.begin(); subIt != it->second.end(); ++subIt)
				container.push_back(*subIt);
		}
		sizeVectorPair *= 2;
		if (pair.size() <= 1)
		{
			if (!pair.empty())
				LastRecursion(sizeVectorPair, VectordyalXyata, mainChaine);
			return;
		}
		MergeInsertSort(sizeVectorPair);
		ReverseRecursion(sizeVectorPair, VectordyalXyata, mainChaine, pend);
	}
	
	void LastRecursion(size_t sizeVectorPair, std::list<int>& VectordyalXyata, std::list<std::list<int> >& mainChaine)
	{
		std::list<std::pair<std::list<int>, std::list<int> > > pairR;
		std::list<int>::iterator it = container.begin();
		for (size_t i = 0; i < sizeVectorPair; ++i)
		{
			std::list<int> LeftVector2;
			std::list<int> RightVector2;
			for (size_t j = 0; j < sizeVectorPair; ++j)
			{
				if(it != container.end())
				{
					LeftVector2.push_back(*it);
					++it;
				}
			}
			
			for (size_t j = 0; j < sizeVectorPair; ++j)
			{
				if(it != container.end())
				{
					RightVector2.push_back(*it);
					++it;
				}
			}
			
			pairR.push_back(std::make_pair(LeftVector2, RightVector2));
		}
		
		mainChaine.clear();
		pend.clear();
		
		for(std::list<std::pair<std::list<int>, std::list<int> > >::iterator it = pairR.begin(); it != pairR.end(); ++it)
		{
			mainChaine.push_back(it->second);
			pend.push_back(it->first);
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
				jacobSequence.push_back(jac);
		}
		
		if(!pend.empty())
			mainChaine.insert(mainChaine.begin(), pend.front());
		
		if(pend.size() >= 2)
		{
			std::list<std::list<int> >::iterator it;
			it = std::lower_bound(mainChaine.begin(), std::next(mainChaine.begin(), 2) , pend.front(), CompareLowerBound);
			mainChaine.insert(it, pend.front());
		}
		
		int begin = 2;
		
		for (std::list<int>::iterator it = jacobSequence.begin(); it != jacobSequence.end(); ++it)
		{
			int j = *it;
			int tmp = j;
			while (j >= begin)
			{
				std::list<std::list<int> >::iterator it2 = mainChaine.begin();
				std::advance(it2, j);
				std::list<std::list<int> >::iterator it3 = std::lower_bound(mainChaine.begin(), mainChaine.end(), *it2, CompareLowerBound);
				mainChaine.insert(it3, *it2);
				--j;
			}
			begin = tmp + 1;
		}
		
		if(!VectordyalXyata.empty())
		{
			std::list<std::list<int> >::iterator it;
			it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
			mainChaine.insert(it, VectordyalXyata);
		}
		
		container.clear();
		for(std::list<std::list<int> >::iterator it = mainChaine.begin(); it != mainChaine.end(); ++it)
		{
			for(std::list<int>::iterator subIt = it->begin(); subIt != it->end(); ++subIt)
				container.push_back(*subIt);
		}
	}
	
private:
	std::list<int> container;
	std::list<std::pair<std::list<int>, std::list<int> > > pair;
	std::list<std::list<int> > pend;
	std::list<int> jacobSequence;
	
	static bool CompareLowerBound(const std::list<int>& a, const std::list<int>& b)
	{
		return a.back() < b.front();
	}
	
	int jacobsthal(int n)
	{
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
	}
	
	void ReverseRecursion(size_t sizeVectorPair, std::list<int>& VectordyalXyata, std::list<std::list<int> >& mainChaine, std::list<std::list<int> >& pend)
	{
		std::list<std::pair<std::list<int>, std::list<int> > > pairR;
		std::list<int>::iterator it = container.begin();
		for (size_t i = 0; i < sizeVectorPair; ++i)
		{
			std::list<int> LeftVector2;
			std::list<int> RightVector2;
			for (size_t j = 0; j < sizeVectorPair; ++j)
			{
				if(it != container.end())
				{
					LeftVector2.push_back(*it);
					++it;
				}
			}
			
			for (size_t j = 0; j < sizeVectorPair; ++j)
			{
				if(it != container.end())
				{
					RightVector2.push_back(*it);
					++it;
				}
			}
			
			pairR.push_back(std::make_pair(LeftVector2, RightVector2));
		}
		
		mainChaine.clear();
		pend.clear();
		
		for(std::list<std::pair<std::list<int>, std::list<int> > >::iterator it = pairR.begin(); it != pairR.end(); ++it)
		{
			if(it != pairR.begin())
			{
				mainChaine.push_back(it->second);
				pend.push_back(it->first);
			}
			else
			{
				mainChaine.push_back(it->first);
				pend.push_back(std::list<int>());
			}
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
				jacobSequence.push_back(jac);
		}
		
		if(!pend.empty())
			mainChaine.insert(mainChaine.begin(), pend.front());
		
		if(pend.size() >= 2)
		{
			std::list<std::list<int> >::iterator it;
			it = std::lower_bound(mainChaine.begin(), std::next(mainChaine.begin(), 2) , pend.front(), CompareLowerBound);
			mainChaine.insert(it, pend.front());
		}
		
		int begin = 2;
		
		for (std::list<int>::iterator it = jacobSequence.begin(); it != jacobSequence.end(); ++it)
		{
			int j = *it;
			int tmp = j;
			while (j >= begin)
			{
				std::list<std::list<int> >::iterator it2 = mainChaine.begin();
				std::advance(it2, j);
				std::list<std::list<int> >::iterator it3 = std::lower_bound(mainChaine.begin(), mainChaine.end(), *it2, CompareLowerBound);
				mainChaine.insert(it3, *it2);
				--j;
			}
			begin = tmp + 1;
		}
		
		if(!VectordyalXyata.empty())
		{
			std::list<std::list<int> >::iterator it;
			it = std::lower_bound(mainChaine.begin(), mainChaine.end(), VectordyalXyata, CompareLowerBound);
			mainChaine.insert(it, VectordyalXyata);
		}
		
		container.clear();
		for(std::list<std::list<int> >::iterator it = mainChaine.begin(); it != mainChaine.end(); ++it)
		{
			for(std::list<int>::iterator subIt = it->begin(); subIt != it->end(); ++subIt)
				container.push_back(*subIt);
		}
	}
};

void usingList(PmergeMe& pmergeMe)
{
	pmergeMe.printBefore();
	pmergeMe.MergeInsertSort(1);
	pmergeMe.printAfter();
}

int main(int argc, char** argv)
{
	if (argc >= 2)
	{
		clock_t timeList;
		try
		{
			PmergeMe pmergeMe;
			if (pmergeMe.fillContainer(argv) == 1)
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
			timeList = clock();
			usingList(pmergeMe);
			timeList = clock() - timeList;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << static_cast<float>(timeList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: " <<  argv[0] << "  <numbers ...>   " << std::endl;
	
	return 0;
}