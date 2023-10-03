/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:40:22 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/03 13:53:26 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <random>

std::vector<int> container;

void    MergePart(int LowerIndex, int middle, int HigherIndex)
{
    // declare two arry with same size the container
    // int array[container.size()];
    int tmpArray[container.size()];
    for(int i=LowerIndex; i<=HigherIndex; i++)
        tmpArray[i] = container.at(i);
    int i = LowerIndex;
    int j = middle + 1;
    int k = LowerIndex;
    while (i<=middle && j<=HigherIndex)
    {
        if (tmpArray[i] <= tmpArray[j])
        {
            container.at(k) = tmpArray[i];
            i++;
        }
        else
        {
            container.at(k) = tmpArray[j];
            j++;
        }
        k++;
    }
    while(i<=middle)
    {
        container.at(k) = tmpArray[i];
        k++;
        i++;
    }
}

void    doMergeSort(int LowerIndex, int HigherIndex)
{
    if(LowerIndex < HigherIndex)
    {
        int middle = LowerIndex + (HigherIndex - LowerIndex) / 2;
        // std::cout << "middle: " << middle << std::endl;
        doMergeSort(LowerIndex, middle);
        doMergeSort(middle + 1, HigherIndex);
        //merge and sort
        MergePart(LowerIndex, middle, HigherIndex);
    }
}
int main()
{

    // container.push_back(2);
    // container.push_back(5);
    // container.push_back(3);
    // container.push_back(8);
    // container.push_back(6);
    // container.push_back(1);
    // container.push_back(4);
    // container.push_back(7);
    // /*print container */
    // for(size_t i=0; i<container.size(); i++)
    //     std::cout << container.at(i) << " ";
    // std::cout << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 10000); // Adjust the range as needed

    for (int i = 0; i < 3000; ++i) {
        int randomInt = distribution(gen);
        container.push_back(randomInt);
    }

    // Print the vector
    std::cout << "numbers after sort : " << std::endl; 
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
    /*inception the implement algorithm the mergeSor*/
    // std::cout << container.size() << std::endl;

    //dived problem to small problem
    doMergeSort(0, container.size()-1);
    std::cout << "numbers before sort : " << std::endl; 
    for(size_t i=0; i<container.size(); i++)
        std::cout << container.at(i) << " ";
    std::cout << std::endl;
    return 0;
}