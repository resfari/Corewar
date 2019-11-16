/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:34 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 15:56:44 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_ld_dir(t_war *war, t_crg *crg)
{
	int arg;
	int pos;
	int reg;

	pos = crg->pos + 2;

	arg = ((war->arena[GG(pos)].code) << 24 | (war->arena[GG(pos + 1)].code) << 16 |
	(war->arena[GG(pos + 2)].code) << 8 | (war->arena[GG(pos + 3)].code));
	reg = war->arena[GG(pos + 4)].code;
	if (reg >= 1 && reg <= 16)
	{
		if (arg == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
		crg->reg[reg] = arg;
	}
	printf("\n arg = %d\n", arg);
	printf("\nregistr = %d\n", reg);
}

void	ft_ld_ind(t_war *war, t_crg *crg)
{
	int arg;
	int new_arg;
	int pos;
	int new_pos;
	int reg;

	pos = crg->pos + 2;
	arg = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
	reg = war->arena[GG(pos + 2)].code;
	
	new_pos = crg->pos + arg % IDX_MOD;
	
	new_arg = ((war->arena[GG(new_pos)].code) << 24 | (war->arena[GG(new_pos + 1)].code) << 16 |
	(war->arena[GG(new_pos + 2)].code) << 8 | (war->arena[GG(new_pos + 3)].code));
	printf("\n POS = %d NEW_POS = %d REG = %d\n", pos, new_pos, reg);
	if (reg >= 1 && reg <= 16)
	{
		crg->reg[reg] = new_arg;
		if (new_arg == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
	}
	printf("\nIND ARG = %d NEW ARG = %d\n", arg, new_arg);
	printf("\n carry = %d\n", crg->carry);
}

void	ft_ld(t_war *war, t_crg *crg)
{
	// printf("\narg = %d\n", crg->args[0]);
	if (crg->args[0] == 5) // first arg == T_DIR
	{
		ft_ld_dir(war, crg);
		ft_move_crg(war, crg, 7);
	}
	else
	{
		ft_ld_ind(war, crg);
		ft_move_crg(war, crg, 5);
	}
	exit(1);
}
