# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: mjordan                                    +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/12/11                               #+#    #+#             #
#    Updated: 2025/12/11                              ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow -Iclap -Ifrag \
				-Iscav -Idiamond

SRCS		= main.cpp clap/ClapTrap.cpp scav/ScavTrap.cpp \
				frag/FragTrap.cpp diamond/DiamondTrap.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
