# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:41:24 by rrhnizar          #+#    #+#              #
#    Updated: 2023/10/11 23:50:42 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

RFLAG = ${CXX} -Wall -Werror -Wextra -std=c++98 -fsanitize=address

%.o : %.cpp
	${RFLAG} -c $< -o $@

all : ${Name}

${Name} : ${OBJ} PmergeMe.hpp
	${RFLAG} ${OBJ} -o ${Name}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${Name}

re : fclean all
