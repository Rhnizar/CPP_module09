/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:10 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/06 12:45:41 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <vector>

int	fillContainerWithData(std::vector<std::pair<std::string, std::string> > *stringPair);
int findPipe(std::string str);
int	CheckYearMonthDay(std::string year, std::string month, std::string day);
#endif