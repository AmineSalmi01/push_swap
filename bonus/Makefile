NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = check_args_bonus.c check_args_utils_bonus.c checker.c ft_atoi_bonus.c utils_bonus.c \
	ft_split_bonus.c functions_utils_bonus.c index_stack_bonus.c push_bonus.c rotate_bonus.c \
	reverse_rotate_bonus.c swap_bonus.c list_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

RED=\033[0;31m
PURPLE=\033[0;35m
NC=\033[0m

all : $(NAME)

$(NAME) : $(OBJS) push_swap_bonus.h
	@$(CC) $(CFLAGS)  $(OBJS) -o $@
	@echo "${PURPLE}BONUS DONE${NC}"

%.o : %.c push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : clean bonus