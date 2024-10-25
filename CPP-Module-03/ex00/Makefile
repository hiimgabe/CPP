NAME 	= ClapTrap
SRC 	= ${wildcard *.cpp}
OBJ 	= ${SRC:.cpp=.o}

FLAGS	= -Wall -Wextra -Werror -std=c++98

GREEN	= \033[38;5;47m
YELLOW	= \033[38;5;226m
RED		= \033[38;5;196m
END 	= \033[0m

%.o:%.cpp
	@c++ ${FLAGS} -g -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@c++ ${FLAGS} ${OBJ} -o ${NAME}
	@echo "${GREEN}${NAME} compiled${END}"

clean:
	@rm -rf ${OBJ}
	@echo "${YELLOW}Deleting objects${END}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}Deleting ${NAME}${END}"

re: fclean all

.PHONY: all clean fclean re