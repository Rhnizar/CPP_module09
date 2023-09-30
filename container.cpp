/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:46:34 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/30 11:53:17 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <utility> // for std::pair
#include <vector>

int main() 
{
    std::vector<std::pair<std::string, std::string> > stringPair;


	stringPair.push_back(std::make_pair("Hello", "World")); 

    std::cout << "First String: " << stringPair.at(0).first << std::endl;
    std::cout << "Second String: " << stringPair.at(0).second << std::endl;

    return 0;
}
