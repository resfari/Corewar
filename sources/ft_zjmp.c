/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:17:38 by pnita             #+#    #+#             */
/*   Updated: 2019/11/19 18:16:08 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void    ft_zjmp(t_war *war, t_crg *crg)
{
	int arg;
	int pos;

    if (crg->carry == 1)
	{
		pos = crg->pos + 1;
		arg = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
		ft_move_crg(war, crg, arg % IDX_MOD);
		// printf("\nzjmp arg = %d\n", arg);
	}
	else
	{
		ft_move_crg(war, crg, 3);
	}
}
