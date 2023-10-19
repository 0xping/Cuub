# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
END = \033[0m

#Texture
BOLD = \033[1m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address

# Add platform-specific flags
UNAME = $(shell uname)
ifeq ($(UNAME),Linux)
	MLX_FLAGS = -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

# Target name
NAME = cub3d
BONUS = cub3d_bonus


LIB = ./lib/lib.a

# Source files
LIB_SRC = $(wildcard ./lib/*.c ./lib/**/*.c)
SRC = $(wildcard ./mandatory/src/*.c  ./mandatory/src/**/*.c)
BONUS_SRC = $(wildcard  ./bonus/src/*.c ./bonus/src/**/*.c)
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS_SRC:.c=.o)

all : $(NAME)


$(LIB) : $(LIB_SRC)
	@echo "$(GREEN)\n⌛ Compiling lib ...$(END)"
	@make -sC ./lib
	@make -sC ./lib/ clean

$(NAME): $(SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(NAME) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully\n$(END)"
	@echo "To start the game, use: $(YELLOW)$(BOLD)./$(NAME) <path_to_a_valid_map>$(END)"


bonus : $(BONUS_SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(BONUS) ...$(END)"
	@$(CC) $(CFLAGS) $(BONUS_SRC) $(LIB) $(MLX_FLAGS) -o $(BONUS)
	@echo "$(GREEN)✅ $(BONUS) compiled successfully\n$(END)"
	@echo "To start the game, use: $(YELLOW)$(BOLD)./$(BONUS) <path_to_a_valid_map>$(END)"


clean :
	@echo "$(RED)\n⌛ removing object files ...$(END)"
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@make -sC  ./lib clean
	@echo "$(RED)🗑️  objects removed \n$(END)"

fclean : clean
	@echo "$(RED)\n⌛ removing $(NAME) ...$(END)"
	@rm -rf $(NAME) $(BONUS)
	@make -sC  ./lib fclean
	@echo "$(RED)🗑️  $(NAME) removed \n$(END)"

re : fclean all

.PHONY: all clean fclean re BONUS
