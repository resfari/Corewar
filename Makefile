#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:27:10 by vbrazhni          #+#    #+#              #
#    Updated: 2018/12/23 18:27:06 by vbrazhni         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM_NAME = asm
COREWAR_NAME = corewar

FLAGS = -Wall -Werror -Wextra

# Libraries and Includes

ASM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
ASM_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

COREWAR_LIBRARIES = -lncurses -lftprintf -L$(FT_PRINTF_DIRECTORY)
COREWAR_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT_DIRECTORY = ./ft_printf/libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

FT_PRINTF_DIRECTORY = ./ft_printf/
FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

# Headers

HEADERS_DIRECTORY = ./includes/

# asm

ASM_HEADERS_LIST = \
	op.h\
	assembler.h\
	operations.h
ASM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(ASM_HEADERS_LIST))

# corewar

COREWAR_HEADERS_LIST = \
	op.h\
	corewar.h
COREWAR_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(COREWAR_HEADERS_LIST))

# Sources

# asm

ASM_SOURCES_DIRECTORY = ./srcs/asm/
ASM_SOURCES_LIST = \
	assembler.c \
	dop_functions.c \
	error_exit.c \
	name_comment.c \
	get_name.c \
	set_arg.c \
	do_with_oper.c \
	detect_op.c \
	lbl.c \
	oper.c \
	arg.c \
	lbl_arg.c \
	join_s_to_buff.c \
	do_with_buff.c \
	delete.c
ASM_SOURCES = $(addprefix $(ASM_SOURCES_DIRECTORY), $(ASM_SOURCES_LIST))

# corewar

COREWAR_SOURCES_DIRECTORY = ./srcs/corewar/
COREWAR_SOURCES_LIST = \
	main.c \
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
	ft_key_detect.c
COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIRECTORY), $(COREWAR_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objs/

# asm

ASM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)asm/
ASM_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_SOURCES_LIST))
ASM_OBJECTS	= $(addprefix $(ASM_OBJECTS_DIRECTORY), $(ASM_OBJECTS_LIST))

# corewar

COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
COREWAR_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_SOURCES_LIST))
COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LIST))

all: $(COREWAR_NAME) $(ASM_NAME)

$(COREWAR_NAME): $(FT_PRINTF) $(COREWAR_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS)
	gcc $(FLAGS) $(COREWAR_LIBRARIES) $(COREWAR_INCLUDES) $(COREWAR_OBJECTS) -o $(COREWAR_NAME)

$(ASM_NAME): $(FT_PRINTF) $(ASM_OBJECTS_DIRECTORY) $(ASM_OBJECTS)
	gcc $(FLAGS) $(ASM_LIBRARIES) $(ASM_INCLUDES) $(ASM_OBJECTS) -o $(ASM_NAME)

$(COREWAR_OBJECTS_DIRECTORY):
	mkdir -p $(COREWAR_OBJECTS_DIRECTORY)

$(ASM_OBJECTS_DIRECTORY):
	mkdir -p $(ASM_OBJECTS_DIRECTORY)

$(COREWAR_OBJECTS_DIRECTORY)%.o : $(COREWAR_SOURCES_DIRECTORY)%.c $(COREWAR_HEADERS)
	gcc $(FLAGS) -c $(COREWAR_INCLUDES) $< -o $@

$(ASM_OBJECTS_DIRECTORY)%.o : $(ASM_SOURCES_DIRECTORY)%.c $(ASM_HEADERS)
	gcc $(FLAGS) -c $(ASM_INCLUDES) $< -o $@

$(FT_PRINTF):
	make -sC $(FT_PRINTF_DIRECTORY)

clean:
	make -sC $(FT_PRINTF_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	make -sC $(FT_PRINTF_DIRECTORY) fclean
	rm -f $(ASM_NAME)
	rm -f $(COREWAR_NAME)

re:
	make fclean
	make all
