NAME		= Identify\ real\ type

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDES	= -I. -Iinclude

SRC_DIR		= src/
SRCS		= main.cpp $(SRC_DIR)Base.cpp $(SRC_DIR)A.cpp $(SRC_DIR)B.cpp $(SRC_DIR)C.cpp

OBJ_DIR		= obj
OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
			mkdir -p $(OBJ_DIR)/$(SRC_DIR)
			$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
