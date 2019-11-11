/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:25:27 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/11 18:12:23 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"


void	ft_add_code_to_arena(t_war *war, int num, int pos)
{
	int i;

	i = 0;
	while (i < war->player[num].code_len)
	{
		war->arena[pos].code = war->player[num].code[i] & 255;
		war->field[pos] = war->player[num].code[i] & 255;
		i++;
		pos++;
	}
}

void	ft_fill_arena(t_war *war)
{
	int i;
	int j; // cause i begin from 1 (we need 0 here(pos for 1st player = 0))
	int pos;

	i = 1;
	j = 0;
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
