# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/11/14 17:04:40 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = corewar

FLAG = -Wall -Wextra -Werror

LIBFT = ft_printf

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = main.c \
		  read_flags_players.c \
		  init_main.c \
		  check_player.c \
		  read_players_code.c \
		  decompose_code.c \
		  check_magic.c \
		  free_exit.c \
		  check_name_and_comment.c \
		  fill_arena.c \
		  check_code.c \
		  fill_crg.c \
		  file_for_some_tests.c \
		  init_reg_in_crg.c \
		  greatings.c \
		  init_opp.c \
		  play_game.c \
		  check_status_of_crg.c \
		  check_argument.c \
		  detect_operation.c \
		  move_crg.c \
		  ft_live.c \
		  ft_ld.c \



SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	gcc -o $(NAME) $(FLAG) $(SRCS) ft_printf/libftprintf.a 

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all