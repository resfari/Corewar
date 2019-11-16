/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:42:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 18:51:30 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_whos_number(t_war *war, int num)
{
	if (num >= 1 && num <= war->numb_players)
		return (1);
	return (0);
}

void	ft_live(t_war *war, t_crg *crg)
{
	
	int arg;
	int pos;
	
	pos = crg->pos + 1;
	war->live++;
	crg->live++;
	arg = ((255 & war->arena[GG(pos)].code) << 24 | (255 & war->arena[GG(pos + 1)].code) << 16 |
	(war->arena[GG(pos + 2)].code) << 8 | (255 & war->arena[GG(pos + 3)].code));
	// printf("Args %d", arg * -1);
	if (ft_whos_number(war, arg * -1) == 1) // mb normal int need to use
	{
		war->winner = arg * - 1;
		ft_move_crg(war, crg, 5);
		// printf("arg = %dpos = %d\n", arg, crg->pos);
	}
	else
	{
		ft_move_crg(war, crg, 5);
	}
}
