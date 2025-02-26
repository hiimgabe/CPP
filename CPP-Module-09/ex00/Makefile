NAME 	= btc
OBJ_DIR	= bin
SRC_DIR	= source/
INC		= include/
SRC 	= ${addprefix ${SRC_DIR}, main.cpp BitcoinExchange.cpp}
OBJ 	= ${patsubst ${SRC_DIR}%.cpp, ${OBJ_DIR}/%.o, ${SRC}}

FLAGS	= -Wall -Wextra -Werror -std=c++98

GREEN	= \033[38;5;47m
YELLOW	= \033[38;5;226m
RED		= \033[38;5;196m
END 	= \033[0m

MODE	= none

ifeq ($(MODE), debug)
	FLAGS += -D DEBUG
endif

${OBJ_DIR}/%.o: ${SRC_DIR}%.cpp | ${OBJ_DIR}
	@c++ ${FLAGS} -g -c $< -o $@
	@echo "[${GREEN}compiling${END}]: $<"

all: ${NAME}

${OBJ_DIR}:
	@mkdir bin/
	@echo "${GREEN}bin created${END}"

${NAME}: ${OBJ}
	@c++ ${FLAGS} -I ${INC} ${OBJ} -o ${NAME}
	@echo "${GREEN}${NAME} executable created${END}"

clean:
	@rm -rf ${OBJ_DIR}
	@echo "${RED}cleaning objects${END}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}${NAME} deleted${END}"

re: fclean all

.PHONY: all clean fclean re
