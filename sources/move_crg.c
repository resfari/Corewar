/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:22:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 19:02:47 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_move_crg(t_war *war, t_crg *crg, int move)
{
	(void)war;
	int new_pos;

	new_pos = crg->pos + move;
	if (war->arena[GG(new_pos)].busy == 0)
	{
		war->arena[GG(crg->pos)].busy = 0;
		crg->pos = GG(new_pos);
		war->arena[GG(crg->pos)].busy = 1;
	}
	else
	{
		crg->in_queue = 1;
		crg->queue_skip = new_pos;
	}
}
