/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/07 12:37:00 by rrhnizar         ###   ########.fr       */
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