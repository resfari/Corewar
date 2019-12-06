/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:38:07 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:00:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"


void	ft_move_sti_reg_error(t_war *war, t_crg *crg)
{
	int res;

	res = 3;
	if (crg->args[1] == 3)
		res += 1;
	else
		res += 2;
	if (crg->args[2] == 3)
		res += 1;
	else
		res += 2;
	ft_move_crg(war, crg, res);
}

void	ft_sti(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int arg2;
	int arg3;
	int i;
	int x;

	pos = crg->pos + 2;
	reg = get_arg_reg(war, pos);
	if (reg >= 1 && reg <= 16)
	{
		pos += 1;
		if (crg->args[1] == 3)
		{
			arg2 = get_arg_reg(war, pos);
			if (arg2 >= 1 && arg2 <= 16)
			{
				arg2 = crg->reg[arg2];
			}
			else
			{
				ft_move_sti_reg_error(war, crg);
				return ;
			}
			pos += 1;
		}
		else if (crg->args[1] == 5)
		{
			arg2 = get_arg_dir(war, pos, 2);
			pos += 2;
		}
		else
		{
			arg2 = get_arg_ind(war, pos);
			arg2 = get_arg_dir(war, crg->pos + arg2 % IDX_MOD, 4);
			pos += 2;
		}
		if (crg->args[2] == 3)
		{
			arg3 = get_arg_reg(war, pos);
			if (arg3 >= 1 && arg3 <= 16)
			{
				arg3 = crg->reg[arg3];
			}
			else
			{
				ft_move_sti_reg_error(war, crg);
				return ;
			}
			pos += 1;
		}
		else
		{
			arg3 = get_arg_dir(war, pos, 2);
			pos += 2;
		}
		i = 0;
		while (i < 4)
		{
			x = crg->pos + (arg2 + arg3) % IDX_MOD + i;
			war->arena[GG((x))].code = (crg->reg[reg] >> (8 * (3 - i))) & 255;
			war->arena[GG((x))].color = crg->player;
			i++;
		}
		ft_move_crg(war, crg, pos - crg->pos);
	}
	else
		ft_move_sti_reg_error(war, crg);
}
