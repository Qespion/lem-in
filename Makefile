.PHONY: all checker push_swap lib minilibx clean fclean re
.SUFFIXES:
CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	lem-in

SRCS_1	=   srcs/lem_in.c

LIBFT	=	libft/libft.a

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

OBJS1    =   $(SRCS_1:.c=.o)

all:	lib lem_in

lib:
	@make -C libft/

lem_in: $(OBJS1)
	@echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I includes/
	@echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS1)

fclean:     clean
	@rm -f $(NAME1) $(LIBFT)

re:         fclean all