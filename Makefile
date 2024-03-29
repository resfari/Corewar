# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/12/17 16:27:46 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAG = -Wall -Wextra -Werror

FT_PRINTF = ft_printf

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = main.c \
		  reading_take_dump.c \
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
		  greatings.c \
		  init_opp.c \
		  init_first_cycle.c \
		  play_game.c \
		  check_status_of_crg.c \
		  check_argument.c \
		  detect_operation.c \
		  move_crg.c \
		  get_arg.c \
		  ft_live.c \
		  ft_ld.c \
		  ft_st.c \
		  ft_add.c \
		  ft_sub.c \
		  ft_and.c \
		  ft_or.c \
		  ft_xor.c \
		  ft_zjmp.c \
		  ft_ldi.c \
		  ft_sti.c \
		  ft_fork.c \
		  ft_aff.c \
		  ft_print.c \
		  ft_key_detect.c \
		  
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(FT_PRINTF)
	gcc -o $(NAME) $(FLAG) $(SRCS) $(FT_PRINTF)/libftprintf.a -lcurses -g

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@rm -f $(OBJS)
	@make clean -C $(FT_PRINTF)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)

re: fclean all