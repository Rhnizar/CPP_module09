/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:32 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/11 20:38:19 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CPP program to illustrate 
// std :: lower_bound 
// #include <bits/stdc++.h> 
// #include <iostream>
// #include <vector>

// // Driver code 
// int main() 
// { 
// 	// Input vector 
// 	std::vector<int> v;
// 	v.push_back(10);
// 	v.push_back(20);
// 	v.push_back(30);
// 	v.push_back(30);
// 	v.push_back(30);
// 	v.push_back(40);
// 	v.push_back(40);

// 	// Print vector 
// 	std::cout << "Vector contains :"; 
// 	for (unsigned int i = 0; i < v.size(); i++) 
// 		std::cout << " " << v[i]; 
// 	std::cout << "\n";

// 	std::vector<int>::iterator low1, low2, low3; 
	
// 	// std :: lower_bound 
// 	// low1 = std::lower_bound(v.begin(), v.end(), 30); 
// 	// low2 = std::lower_bound(v.begin(), v.end(), 35); 
// 	// low3 = std::lower_bound(v.begin(), v.end(), 55); 
// 	// std :: upper_bound 
// 	low1 = std::upper_bound(v.begin(), v.end(), 30); 
// 	low2 = std::upper_bound(v.begin(), v.end(), 35); 
// 	low3 = std::upper_bound(v.begin(), v.end(), 55); 

// 	// Printing the lower bounds 
// 	std::cout 
// 		<< "\nlower_bound for element 30 at position : "
// 		<< (low1 - v.begin()); 
// 	std::cout 
// 		<< "\nlower_bound for element 35 at position : "
// 		<< (low2 - v.begin()); 
// 	std::cout 
// 		<< "\nlower_bound for element 55 at position : "
// 		<< (low3 - v.begin()); 

// 	return 0; 
// } 


// #include <iostream>
// #include <vector>
// #include <algorithm>

// bool Comparelower_boud(std::vector<int> cmp1, std::vector<int> cmp2)
// {
// 	return cmp1 <= cmp2;
// }
// int main() 
// {
//     std::vector<std::vector<int> > vec;
// 	std::vector<int> vec2;

//     std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), vec2, Comparelower_boud);


//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

bool CompareLowerBound(const std::vector<int>& cmp1, const std::vector<int>& cmp2) 
{
    return cmp1.back() <= cmp2.back();
}

int main()
{
    std::vector<std::vector<int> > vec;
    std::vector<int> vec2;

    // Ensure that vec is sorted before using lower_bound
    std::sort(vec.begin(), vec.end(), CompareLowerBound);

    std::vector<std::vector<int> >::iterator it = std::lower_bound(vec.begin(), vec.end(), vec2, CompareLowerBound);

    if (it != vec.end())
        std::cout << "Lower bound found." << std::endl;
	else
        std::cout << "Lower bound not found." << std::endl;


    return 0;
}
