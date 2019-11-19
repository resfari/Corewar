/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:34 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/19 17:15:32 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_ld_dir(t_war *war, t_crg *crg)
{
	int arg;
	int pos;
	int reg;

	pos = crg->pos + 2;

	arg = get_arg_dir(war, pos, 4);
	// arg = ((255 & war->arena[GG(pos)].code) << 24 | (255  &war->arena[GG(pos + 1)].code) << 16 |
	// (255 & war->arena[GG(pos + 2)].code) << 8 | (255 & war->arena[GG(pos + 3)].code));
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
	// printf("\n value = %d\n", arg);
	// printf("\nregistr = %d\n", reg);
}

void	ft_ld_ind(t_war *war, t_crg *crg, int cases)
{
	int arg1;
	int arg2;
	int pos;
	int reg;

	pos = crg->pos + 2;
	arg1 = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
	reg = war->arena[GG(pos + 2)].code;
	
	if (cases == 0) // if its ld
		pos = crg->pos + arg1 % IDX_MOD;
	else //if its LLD
		pos = crg->pos + arg1; 
	arg2 = get_arg_dir(war, pos, 4);
	printf("\n POS = %d NEW_POS = %d REG = %d\n", pos, pos, reg);
	if (reg >= 1 && reg <= 16)
	{
		crg->reg[reg] = arg2;
		if (arg2 == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
	}
	printf("\nIND ARG = %d NEW ARG = %d\n", arg1, arg2);
	printf("\n carry = %d\n", crg->carry);
}

void	ft_ld(t_war *war, t_crg *crg, int cases)
{
	// printf("\narg = %d\n", crg->args[0]);
	if (crg->args[0] == 5) // first arg == T_DIR
	{
		ft_ld_dir(war, crg);
		ft_move_crg(war, crg, 7);
	}
	else
	{
		ft_ld_ind(war, crg, cases);
		ft_move_crg(war, crg, 5);
	}
}
