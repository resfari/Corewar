/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:42:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/22 15:25:37 by lgeorgia         ###   ########.fr       */
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
	arg = get_arg_dir(war, pos, 4);

	// if (war->live_count >100 && war->live_count < 150)
	// {
	// 	printf("\nLIVE: DIR = %d pos = %d\n", arg, crg->pos);
	// }
	// war->live_count++;

	if (ft_whos_number(war, arg) == 1) // mb normal int need to use
	{
		war->winner = arg;
		war->live++;
		crg->live = 1;
		ft_move_crg(war, crg, 5);
	}
	else
	{
		ft_move_crg(war, crg, 5);
	}
}
