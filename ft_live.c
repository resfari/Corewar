/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:42:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/11 20:55:09 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"

void	ft_live(t_war *war, t_crg *crg)
{
	war->live++;
	int arg;
	int pos;
	char *ptr;
	
	pos = crg->pos + 1;
	ptr = (char*)&(war->field[1]);

	arg = ((255 & ptr[0]) << 24 | (255 & ptr[1]) << 16 |
	(255 & ptr[2]) << 8 | (255 & ptr[3]));
	if (crg->player * -1 == arg) // mb normal int need to use
	{
		war->winner = crg->player;
		ft_move_crg(war, crg, 5);
		// printf("arg = %dpos = %d\n", arg, crg->pos);
		war->live++;
		crg->live = 1;
	}
	else
	{
		ft_move_crg(war, crg, 5);
	}
}
