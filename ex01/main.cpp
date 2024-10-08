/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:42:45 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/10/04 13:47:33 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if(argc==2)
		{
			if (CheckString_AndFillContainer(argv[1]) == 1)
				return 1;
		}
		else
		{
			std::cerr << "Usage: ./RPN <string>" << std::endl;
			return 1;
		}
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (int i)
	{
		std::cerr << "Error: division by " << i << std::endl;
	}
	return 0;
}

/* result the how to calculate example 1
>>> 8*9
72
>>> 72 - 9
63
>>> 63 - 9
54
>>> 54 - 9
45
>>> 45 - 4
41
>>> 41 + 2
43
>>> 41 + 1
42
*/


/* result the how to calculate example 2
>>> 7 * 7
49
>>> 49 - 7
42
>>> */

 

 /* result the ./RPN "1 2 * 2 / 2 * 2 4 - +"
 1 2 * = 2
 2 / 2 = 1
 1 * 2 = 2
 2 - 4 = -2 
 2 + (-2) = 0
 */

