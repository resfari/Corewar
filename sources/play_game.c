/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 17:02:39 by lgeorgia         ###   ########.fr       */
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
			war->numb_crg++;
		}
		help = help->next;
	}
	return (war->numb_crg);
}

void	ft_play_game(t_war *war)
{
	t_crg *help;

	ft_init_first_cycle(war);
	if (war->need_to_draw == 1)
		ft_init_ncurses();
	while (1)
	{
		help = war->top;
		ft_check_status_of_crg(war, help);
		if (war->to_die <= 0)
		{
				if (war->need_to_draw == 1)
					ft_print_1(war, 1);
				else
					ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
				ft_free_exit(war, 0);
		}
		if (war->cycle == war->to_die)
		{
			war->check_num++;
			if (ft_check_live_crg(war) == 0)
			{
				if (war->need_to_draw == 1)
					ft_print_1(war, 1);
				else
					ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
				ft_free_exit(war, 0);
			}
			if (war->check_num == 10 || war->live >= NBR_LIVE)
			{

				war->to_die -= CYCLE_DELTA;
				war->check_num = 0;
			}
			war->cycle = 0;
			war->live = 0;
		}
		if (war->need_to_draw == 0 && war->dump_cycle == war->all_cycle && (war->dump == 1 || war->dump2 == 1))
		{
			ft_print_arena(war);
			ft_free_exit(war, 0);
		}
		if (war->need_to_draw == 1)
		{
			ft_print_1(war, 0);
			// usleep(50000000);
		}
		war->cycle++;
		war->all_cycle++;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
	ft_free_exit(war, 0);
}
