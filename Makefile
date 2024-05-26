NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = check_args_utils.c check_args.c ft_atoi.c ft_split.c functions_utils.c \
	  index_stack.c push.c rotate.c swap.c reverse_rotate.c list.c main.c simple_sort.c functions_sort_utils.c 

OBJS=$(SRC:.c=.o)

RED=\033[0;31m
PURPLE=\033[0;35m
NC=\033[0m

all : $(NAME)

$(NAME) : $(OBJS) push_swap.h
	@$(CC) $(CFLAGS)  $(OBJS) -o $@
	@echo "${PURPLE}PUSH SWAP DONE${NC}"

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)
	@make clean -C bonus

fclean : clean
	@$(RM) $(NAME)
	@echo "${RED}CLEANING DONE${NC}"
	@make fclean -C bonus

bonus :
	@make -C bonus

re : fclean all bonus

.PHONY : clean bonus