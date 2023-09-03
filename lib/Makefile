CC = cc
C_FLAGS = -Wall -Wextra -Werror
NAME = lib.a

SRC = $(wildcard ./*.c ./**/*.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(C_FLAGS) -c $^ -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all