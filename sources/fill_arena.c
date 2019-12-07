/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:25:27 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:57:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_add_code_to_arena(t_war *war, int num, int pos)
{
	int i;

	i = 0;
	while (i < war->player[num].code_len)
	{
		war->arena[pos].code = war->player[num].code[i] & 255;
		war->arena[pos].color = num;
		war->arena[pos].busy = 0;
		war->arena[pos].crg_clr = 0;
		i++;
		pos++;
	}
}

void	ft_fill_arena(t_war *war)
{
	int i;
	int j;
	int pos;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		war->arena[i].code = '\0';
		war->arena[i].color = 0;
		war->arena[i].busy = 0;
		war->arena[i].crg_clr = 0;
		i++;
	}
	i = 1;
	while (i <= war->numb_players)
	{
		pos = (MEM_SIZE / war->numb_players) * j;
		war->player[i].start_pos = pos;
		war->player[i].live = 0;
		ft_add_code_to_arena(war, i, pos);
		i++;
		j++;
	}
}
