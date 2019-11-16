/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../include/corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:02:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/12 18:49:10 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include "../ft_printf/include/ft_printf.h"
# include "op.h"

# define REG 3
# define DIR 5
# define IND 7

# define WP(x) (x > 4095 ? x % 4096 : x)
# define GG(x) (x % MEM_SIZE < 0 ? x % MEM_SIZE + MEM_SIZE : x % MEM_SIZE)



# define MAX_CODE_SIZE  (COMMENT_LENGTH + CHAMP_MAX_SIZE + PROG_NAME_LENGTH)

typedef struct			s_opp
{
	int					arg_len;
	int					types[3];
	int					dir_size;
	int					cycle;
}						t_opp;

typedef struct			s_player
{
	int                 live;
    char                *path;
    char                comment[COMMENT_LENGTH + 1];
    char                name[PROG_NAME_LENGTH + 1];
    char                code[CHAMP_MAX_SIZE + 1];
	int					code_len;
    int                 start_pos;
    int                 text_len;
    char                text[MAX_CODE_SIZE + 1];
}						t_player;

typedef struct			s_arena
{
	char				code;
	int					busy;
}						t_arena;

typedef struct			s_crg
{
	struct s_crg		*next;
	struct s_crg		*prev;
	int					player;
	int					pos;
	int					uniq_num;
	int					carry;
	int					cycle_of_live; //last time execute live
	int					to_die;
	int					to_do; //amount of cycles for execute operation
	int					bytes_to_go; //amount of bytes need to jump for next operation
	int					reg[REG_NUMBER + 1]; //wtf is this?
	int					die;
	int					moved;
	char				*code; // delete?
	int					op;
	int					args[3];
	int					live;
}						t_crg;

typedef struct			s_war
{
	t_player            player[5];
	t_arena				arena[MEM_SIZE];
    char                **argv;
    int                 argc;
    int                 reserved_num[5];
    int                 reserved_wo_n[5];
    int                 numb_players;
	int					numb_crg; //how many crg alive
	t_crg				*top;
	t_crg				*bot;
	int					winner; //parametr is responsible for player who live last time
	int					cycle;
	int					to_die;
	int					live;
	int					check_num;
	int					uniq; //last uniq number for crg
	t_opp				opp[17];
	char				field[MEM_SIZE];
	int					all_cycle;

}						t_war;

void    ft_read_file(char *name_file);
void    ft_read_flags_players(t_war *war); // no support flags now, only order of players realised
void    ft_init_main(t_war *war, char **argv, int argc); // init main struct called WAR
int     ft_give_free_num(t_war *war); 
int     ft_check_free_num(t_war *war, int num);
int     ft_check_valid_num(t_war *war, char *line);
int     ft_check_order_amount_players(t_war *war); 
void    ft_read_players_code(t_war *war);
void	ft_decompose_pl_code(t_war *war);
void	ft_free_exit(t_war *war, int n_error);
void	ft_check_magic(t_war *war, int num);
void	ft_check_name(t_war *war, int num);
void	ft_check_comment(t_war *war, int num);
void	ft_check_code(t_war *war, int num);
void	ft_fill_arena(t_war *war);
void	ft_fill_crg(t_war *war);
void	ft_greatings(t_war *war);
t_crg	*ft_init_reg_in_crg(t_crg *crg, int num);
void	ft_check_status_of_crg(t_war *war, t_crg *crg);
void	ft_init_opp(t_war *war);


void	ft_play_game(t_war *war);
void	ft_detect_operation(int op, t_war *war, t_crg *crg);
void	ft_live(t_war *war, t_crg *crg);
void	ft_check_status_of_crg(t_war *war, t_crg *crg);
int		ft_check_argument(t_war *war, t_crg *crg, int oper);
void	ft_move_crg(t_war *war, t_crg *crg, int move);


//test functions (prints, etc)
void	ft_print_crg_list(t_war *war); //print list karetok
void	ft_print_code_for_each_player(t_war *war); //print code for each player
void	ft_print_arena(t_war *war);
void	ft_print_text(t_war *war);
void	ft_test_bytes(t_war *war, int num);
void	ft_test_4bytes(t_war *war, int num);
void	ft_ld(t_war *war, t_crg *crg);
void	ft_st(t_war *war, t_crg *crg);
void	ft_add(t_war *war, t_crg *crg);
void	ft_sub(t_war *war, t_crg *crg);
void	ft_and(t_war *war, t_crg *crg);
void	ft_or(t_war *war, t_crg *crg);
void	ft_xor(t_war *war, t_crg *crg);
void    ft_zjmp(t_war *war, t_crg *crg);
void	ft_andor_calc_move(t_war *war, t_crg *crg);

#endif
