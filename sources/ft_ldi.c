/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:37:22 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:59:27 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_ldi_find_bytes(t_war *war, t_crg *crg, int arg1, int arg2, int cases)
{
	int new_pos;
	unsigned int bytes;

	if (cases == 0)
		new_pos = crg->pos + (arg1 + arg2) % IDX_MOD;
	else
	{
		new_pos = crg->pos + (arg1 + arg2);
	}
	
	bytes = get_arg_dir(war, new_pos, 4);
	return ((int)bytes);
}

int		ft_ldi_take_arg(t_war *war, t_crg *crg, int pos, int arg)
{
	unsigned int dir;
	int reg;
	unsigned short i_pos;

	if (crg->args[arg] == 3)
	{
		reg = get_arg_reg(war, pos);
		if (reg >= 1 && reg <= 16)
			return (crg->reg[reg]);
	}
	else if (crg->args[arg] == 5)
	{
		dir = get_arg_dir(war, pos, 2);
		return ((short)dir);
	}
	else
	{
		i_pos = get_arg_ind(war, pos);
		dir = get_arg_dir(war, crg->pos + i_pos % IDX_MOD, 4);
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
	arg1 = ft_ldi_take_arg(war, crg, pos, 0);
	if (crg->args[0] == 3)
		pos += 1;
	else
		pos += 2;
	arg2 = ft_ldi_take_arg(war, crg, pos, 1);
	if (crg->args[1] == 3)
		pos += 1;
	else
		pos += 2;
	arg3 = war->arena[GG((pos))].code;
	if (arg3 >= 1 && arg3 <= 16)
	{
		if ((crg->args[0] == 3 && arg1 < 1 && arg1 > 16) || (crg->args[1] == 3 && arg2 < 1 && arg2 > 16))
		{
			ft_move_crg(war, crg, pos - crg->pos + 1);
			return ;
		}
		crg->reg[arg3] = ft_ldi_find_bytes(war, crg, arg1, arg2, cases);
	}
	ft_move_crg(war, crg, pos - crg->pos + 1);
}
