/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:42:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/25 16:54:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_whos_number(t_war *war, int num)
{
	if (num <= -1 && num >= war->numb_players * -1)
		return (1);
	return (0);
}

void	ft_live(t_war *war, t_crg *crg)
{
	
	int arg;
	int pos;
	
	pos = crg->pos + 1;
	arg = get_arg_dir(war, pos, 4);
	war->live++;
	crg->live = 1;
	if (ft_whos_number(war, arg) == 1) // mb normal int need to use
	{
		war->winner = arg * - 1;
		ft_move_crg(war, crg, 5);
	}
	else
	{
		ft_move_crg(war, crg, 5);
	}
	// if (war->live_count < 30)
	// {
	// 	printf("\nLIVE: DIR = %d pos = %d\n", arg, crg->pos);
	// }
	// war->live_count++;
}
