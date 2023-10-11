/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:48:15 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/11 12:46:00 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // Include the <cstdlib> for strtod
#include <vector>


class PmergeMe
{
	public:
		std::vector<int> container;
		// std::vector<int> VectordyalXyata;
		std::vector<std::vector<int> > VectordyalXyata;
		// std::vector<std::pair<std::vector<int>, std::vector<int> > > mainChaine;
		// std::vector<std::pair<std::vector<int>, std::vector<int> > > pend;
		std::vector<std::vector<int> > mainChaine;
		std::vector<std::vector<int> > pend;
		// std::vector<std::pair<std::vector<int>, std::vector<int> > > pair;
		
		PmergeMe(){}
		~PmergeMe(){}
};

int	isInteger(std::string str);