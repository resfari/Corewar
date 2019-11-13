/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:42:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/12 18:29:33 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
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
	char *ptr;
	
	pos = crg->pos + 1;
	ptr = (char*)&(war->field[pos]);
	war->live++;
	crg->live++;
	arg = ((255 & ptr[0]) << 24 | (255 & ptr[1]) << 16 |
	(255 & ptr[2]) << 8 | (255 & ptr[3]));
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
