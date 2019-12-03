/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:34 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/03 16:42:27 by lgeorgia         ###   ########.fr       */
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
	reg = war->arena[GG(pos + 4)].code;

	// if (war->ld_count < 30)
	// 	printf("\nLD: value = %d reg = %d\n", arg, reg);
	// war->ld_count++;

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
	arg1 = get_arg_ind(war, pos);
	reg = war->arena[GG(pos + 2)].code;
	
	if (cases == 0) // if its ld
		pos = crg->pos + arg1 % IDX_MOD;
	else //if its LLD
		pos = crg->pos + arg1; 
	arg2 = get_arg_dir(war, pos, 4);

	// if (war->ld_count < 10)
	// 	printf("\nLD IND: value1 = %d value = %d reg = %d\n", arg1, arg2, reg);
	// war->ld_count++;
	
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

}

void	ft_ld(t_war *war, t_crg *crg, int cases)
{
	// printf("\nLD HERE\n");
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
