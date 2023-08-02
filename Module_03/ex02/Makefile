NAME = scavTrap
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++


SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)


.PHONY : all clean fclean re