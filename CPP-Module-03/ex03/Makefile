NAME		= DiamondTrap
OBJ_DIR		= bin
SRC_DIR		= source
INC			= include
SRC			= $(wildcard $(SRC_DIR)/*.cpp)
OBJ			= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
FLAGS		= -Wall -Wextra -Werror -std=c++98

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@c++ $(FLAGS) -g -c $< -o $@
	@echo "[$(GREEN)compiling$(RESET)]: $<"

all: $(NAME)
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

$(OBJ_DIR):
	@mkdir bin/

$(NAME): $(OBJ)
	@c++ $(FLAGS) -I $(INC) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Deleting object files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Deleting $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re