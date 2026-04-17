NAME		= polymorphism

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDES	= -I. \
			  -IAnimal \
			  -IAnimal/Cat \
			  -IAnimal/Dog \
			  -IWrongAnimal \
			  -IWrongAnimal/WrongCat

SRCS		= main.cpp \
			  Animal/Animal.cpp \
			  Animal/Cat/Cat.cpp \
			  Animal/Dog/Dog.cpp \
			  WrongAnimal/WrongAnimal.cpp \
			  WrongAnimal/WrongCat/WrongCat.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
			$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
