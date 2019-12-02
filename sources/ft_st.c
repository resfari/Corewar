/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:26:20 by pnita             #+#    #+#             */
/*   Updated: 2019/12/02 15:43:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_st_reg(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int new_reg;

	pos = crg->pos + 2;
	reg = war->arena[GG(pos)].code;
	if (reg >= 1 && reg <= 16)
	{
		pos += 1;
		new_reg = war->arena[GG(pos)].code;

		//testing
		// if (war->st_count > 50 && war->st_count < 100)
		// {
		// 	printf("\nST REG:   reg = %d,  pos = %d   crg->pos = %d\n", reg,  new_reg, crg->pos);
		// }
		// war->st_count++;

		if (new_reg >= 1 && new_reg <= 16)
		{
			crg->reg[new_reg] = crg->reg[reg];
		}
	}
}

void	ft_st_ind(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int	ind;
	int i;

	pos = crg->pos + 2;
	ind = 0;

	reg = war->arena[GG(pos)].code;
	ind = get_arg_ind(war, crg->pos + 3);
	
	ind = ind % IDX_MOD;
	pos = crg->pos + ind;
	
	// if (war->st_count < 50)
	// {
	// 	printf("\nST IND:   reg = %d,  pos = %d   crg->pos = %d reg[reg] = %d\n", reg,  ind, crg->pos, crg->reg[reg]);
	// }
	// war->st_count++;

	if (reg >= 1 && reg <= 16)
	{
		i = 0;
		// printf("\npos = %d\n", GG(pos + i));
		while (i < 4)
		{
			war->arena[GG(pos + i)].code = (crg->reg[reg] >> (8 * (3 - i))) & 255;
			war->arena[GG(pos + i)].color = crg->player;
			i++;
		}
	}
	// ft_print_1(war);
	// exit(1);
}

void	ft_st(t_war *war, t_crg *crg)
{
	if (crg->args[1] == 3)
	{
		ft_st_reg(war, crg);
		ft_move_crg(war, crg, 4);
	}
	else
	{
		ft_st_ind(war, crg);
		ft_move_crg(war, crg, 5);
	}
}
