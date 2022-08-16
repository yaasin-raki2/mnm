NAME = minishell

SRCS = main.c HELP_ME. spilt_plus_plus.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

INCLUDES = $(LIBFT)/.

all:
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	@$(CC) $(FLAGS) $(SRCS) -L $(LIBFT) -lft -lreadline -o $(NAME) -I $(INCLUDES)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
