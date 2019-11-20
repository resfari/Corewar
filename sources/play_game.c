/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/20 20:06:09 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_init_first_cycle(t_war *war)
{
	t_crg *help;
	int opp;

	help = war->top;
	while (help)
	{
		opp = (int)(war->arena[help->pos].code & 255);
		// printf("\ninit opp in start = %d\n", opp);
		if (opp > 0 && opp < 17)
		{
			help->to_do = war->opp[opp].cycle;
			help->op = opp;
		}
		else
		{
			help->to_do = 0;
			help->op = -1;
		}
		war->arena[help->pos].crg_clr = help->player;
		war->arena[help->pos].busy = 1;
		help = help->next;
	}
}

int	ft_check_live_crg(t_war *war)
{
	t_crg *help;

	help = war->top;
	war->numb_crg = 0;
	while (help)
	{
		if (help->live == 0)
		{
			war->arena[GG(help->pos)].busy = 0;
			war->arena[GG(help->pos)].crg_clr = 0;
			help->die = 1;
		}
		if (help->die == 0)
		{
			help->live = 0;
			war->test_numb++;
			war->numb_crg++;
		}
		help = help->next;
	}
	return (war->numb_crg);
}

void	ft_play_game(t_war *war)
{
	t_crg *help;
	int key;

	//init first round, to_do count operation etc
	ft_init_first_cycle(war); // add free or busy because of crg
	ft_init_ncurses();
	while ((key = getch()) != 27)
	{
		help = war->top;
		// printf("\ncycles = %d\n", war->cycle);
		if (war->to_die <= 0)
		{
				ft_putstr("\nWinner is player number ");
				ft_putnbr(war->winner);
				write(1, "\n", 1);
				printf("CYCLE MAX = %d DIE<<<<<= 0\n", war->all_cycle);
				exit(1);
		}
		if (war->cycle == war->to_die)
		{
			war->check_num++;
			// printf("\nnumb of crg = %d\n", war->numb_crg);
			if (ft_check_live_crg(war) == 0) // someone alive and kill no life crg
			{
				ft_putstr("\nWinner is player number ");
				ft_putnbr(war->winner);
				write(1, "\n", 1);
				printf("CYCLE MAX = %d war_to_die = %d\n", war->all_cycle, war->to_die);
				exit(1);
			}
			if (war->check_num == 10 || war->live >= NBR_LIVE)
			{

				war->to_die -= CYCLE_DELTA;
				war->check_num = 0;
			}
			war->cycle = 0;
			war->live = 0;
		}
		ft_check_status_of_crg(war, help);
		ft_print_1(war);
		war->cycle++;
		war->all_cycle++;
		// printf("MAX CYCLE = %d CYCLE_TO_DIE = %d\n", war->all_cycle, war->to_die);
		// printf("pos 1 pl = %d pos 2 pl = %d\n", war->bot->pos, war->top->pos);
	}
}
