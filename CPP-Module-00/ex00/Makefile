NAME 	= megaphone
SRC 	= megaphone.cpp
OBJ 	= ${SRC:.cpp=.o}

RM 		= rm -f
CFLAGS	= -Wall -Wextra -Werror -std=c++98

GREEN	= \033[38;5;47m
YELLOW	= \033[38;5;226m
RED		= \033[38;5;196m
END 	= \033[0m

.cpp.o:
	@c++ ${CFLAGS} -c $< -o ${<:.cpp=.o}
	@echo "${GREEN}compiling${END}: $<"

${NAME}: ${OBJ}
	@c++ ${OBJ} -o ${NAME}
	@echo "${GREEN}${NAME} created${END}"

all: ${NAME}

clean:
	@${RM} ${OBJ}
	@echo "${RED}cleaning objects${END}"

fclean: clean
	@${RM} ${NAME}
	@echo "${RED}${NAME} deleted${END}"

re: fclean all

.PHONY: all clean fclean re