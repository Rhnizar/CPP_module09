/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacob.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:02:05 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/16 08:49:40 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

void PmergeMe::ReverseRecursion(size_t sizeVectorPair)
{
    // ... (previous code remains the same)
    
    // Generate Jacobsthal sequence
    jacobSequence.clear();
    for (size_t i = 0; i < pend.size(); i++)
        jacobSequence.push_back(jacobsthal(i));

    // Sort pend vectors based on Jacobsthal sequence
    std::vector<std::pair<std::vector<int>, int>> pendWithIndex;
    for (size_t i = 0; i < pend.size(); i++) {
        pendWithIndex.push_back(std::make_pair(pend[i], jacobSequence[i]));
    }

    // Sort pend vectors by Jacobsthal sequence (ascending order)
    std::sort(pendWithIndex.begin(), pendWithIndex.end(), CompareByJacobsthal);

    // Insert pend vectors into mainChaine based on Jacobsthal sequence
    for (const auto& pendPair : pendWithIndex) {
        std::vector<std::vector<int>>::iterator it;
        it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pendPair.first, CompareLowerBound);
        mainChaine.insert(it, pendPair.first);
    }

    // ... (rest of the code remains the same)
}

// bool CompareLowerBound(const int& a, const int& b)
// {
//     return a < b;
// }

// int jacobsthal(size_t n)
// {
//     return static_cast<int>((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
// }

// int main()
// {
//     std::vector<int> pend; /* Initialize pend vector */
//     std::vector<int> mainChaine; // Initialize mainChaine vector
//     std::vector<int> jacobSequence;

// 	pend.push_back(5);
// 	pend.push_back(7);
// 	pend.push_back(1);
// 	pend.push_back(2);
//     for (size_t i = 0; i < pend.size(); i++)
//         jacobSequence.push_back(jacobsthal(i));
// 	for (size_t i = 0; i < jacobSequence.size(); i++)
// 		std::cout << jacobSequence.at(i) << " ";
// 		std::cout << std::endl;
//     size_t pos = 0;

//     for (size_t i = 0; i < jacobSequence.size(); i++)
// 	{
//         for (int j = jacobSequence[i] - 1; j >= pos; j--)
// 		{
//             std::vector<int>::iterator it = std::lower_bound(mainChaine.begin(), mainChaine.end(), pend[j], CompareLowerBound);
//             mainChaine.insert(it, pend[j]);
//         }
//         pos = jacobSequence[i];
//     }
//     // mainChaine now contains the sorted elements from pend based on Jacobsthal sequence
//     return 0;
// }
