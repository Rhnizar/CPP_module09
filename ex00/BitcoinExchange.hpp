/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:24:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/11 13:24:41 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib> // Include the <cstdlib> for strtod

int	fillContainerWithData(std::set<std::pair<std::string, std::string> > *stringPair);
int findPipe(std::string str);
int	CheckYearMonthDay(std::string year, std::string month, std::string day);
#endif