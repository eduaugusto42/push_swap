# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliopestana <juliopestana@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 17:24:11 by eduaaugu          #+#    #+#              #
#    Updated: 2026/07/31 10:52:59 by eduaaugu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = main.c \
	  algorithm/simple.c \
	  algorithm/medium.c \
	  algorithm/complex.c \
	  algorithm/algorithm_utils.c \
	  benchmark/init_stats.c \
	  benchmark/print_benchmark.c \
	  operations/push.c \
	  operations/reverse_rotate.c \
	  operations/rotate.c \
	  operations/swap.c \
	  parser/input_utils.c \
	  parser/parse_command_line.c \
	  parser/parser_flags.c \
	  parser/validation.c \
	  stack/stack_lifecycle.c \
	  stack/stack_pop.c \
	  stack/stack_push.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
