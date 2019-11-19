/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:37:22 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/19 18:16:32 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_ldi_find_bytes(t_war *war, t_crg *crg, int arg1, int arg2, int cases)
{
	int new_pos;
	unsigned int bytes;

	if (cases == 0 || crg->args[0] == 7 || crg->args[1] == 7)
		new_pos = crg->pos + (arg1 + arg2) % IDX_MOD; // fix with crg->pos
	else
	{
		new_pos = crg->pos + (arg1 + arg2);
	}
	bytes = ((war->arena[GG(new_pos)].code) << 24 | (war->arena[GG(new_pos + 1)].code) << 16 |
	(war->arena[GG(new_pos + 2)].code) << 8 | (war->arena[GG(new_pos + 3)].code));
	return ((int)bytes);
}

int		ft_ldi_take_arg(t_war *war, t_crg *crg, int pos)
{
	unsigned int dir;
	int reg;
	unsigned short i_pos;

	if (crg->args[0] == 3)
	{
		reg = war->arena[GG(pos)].code;
		if (reg >= 1 && reg <= 16)
			return (reg);
	}
	else if (crg->args[1] == 5)
	{
		dir = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
		return ((short)dir);
	}
	else
	{
		i_pos = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
		dir = ((war->arena[GG((int)i_pos)].code) << 24 | (war->arena[GG((int)i_pos + 1)].code) << 16 |
	(war->arena[GG((int)i_pos + 2)].code) << 8 | (war->arena[GG((int)i_pos + 3)].code));
		return ((int)dir);
	}	
	return (0);
}

void	ft_ldi(t_war *war, t_crg *crg, int cases)
{
	int arg1;
	int arg2;
	int pos;
	int arg3;

	pos = crg->pos + 2;
	arg1 = ft_ldi_take_arg(war, crg, pos);
	// printf("\n arg1 = %d\n", arg1);
	if (crg->args[0] == 3)
		pos += 1;
	else
		pos += 2;
	arg2 = ft_ldi_take_arg(war, crg, pos);
	// printf("\n arg2 = %d\n", arg2);
	if (crg->args[0] == 3)
		pos += 1;
	else
		pos += 2;
	arg3 = war->arena[GG(pos)].code;
	// printf("\n arg3 = %d\n", arg3);
	if (arg3 >= 1 && arg3 <= 16)
	{
		crg->reg[arg3] = ft_ldi_find_bytes(war, crg, arg1, arg2, cases);
		// printf("\ncrg reg = %d\n", crg->reg[arg3]);
	}
	// printf("\npos = %d\n", pos - crg->pos + 1);
	ft_move_crg(war, crg, pos - crg->pos + 1); // +1 cause need skip last arg == T_REG
}
