/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:22:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/03 17:25:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_move_crg(t_war *war, t_crg *crg, int move_to)
{
	(void)war;
	int new_pos;
	int prev_pos;

	new_pos = GG(crg->pos + move_to);
	prev_pos = GG(crg->pos);
	war->arena[prev_pos].busy -= 1;

	
	if (war->arena[new_pos].busy <= 0)
	{
		war->arena[new_pos].busy = 1;
		war->arena[new_pos].crg_clr = crg->player;
	}
	else
	{
		war->arena[new_pos].busy += 1;
	}
	if (war->arena[prev_pos].busy <= 0)
	{
		war->arena[prev_pos].busy = 0;
		war->arena[prev_pos].crg_clr = 0;
	}
	crg->pos = GG(new_pos);
	// if (new_pos == 4100 && prev_pos == 4094 && war->all_cycle > 4000)
	// {
	// 	ft_printf("\nMOVE:   new_pos = %d prev_pos = %d  my_pos = %d\n", new_pos, prev_pos, crg->pos);
	// }
	// printf("crg->pos = %d  ", crg->pos);
}
