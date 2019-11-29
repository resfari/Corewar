/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:38:07 by pnita             #+#    #+#             */
/*   Updated: 2019/11/29 17:37:36 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_sti(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int arg2;
	int arg3;
	int i;

	// printf("\n%d %d %d\n", crg->args[0], crg->args[1], crg->args[2]);
	pos = crg->pos + 2;
	reg = get_arg_reg(war, pos);
	// printf("reg = %d\n", reg);
	if (reg >= 1 && reg <= 16)
	{
		pos += 1;
		// arg2
		if (crg->args[1] == 3)
		{
			arg2 = get_arg_reg(war, pos);
			if (arg2 >= 1 && arg2 <= 16)
			{
				arg2 = crg->reg[arg2];
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
			arg2 = get_arg_dir(war, pos + arg2 % IDX_MOD, 4);
			pos += 2;
		}
		// arg3
		if (crg->args[2] == 3)
		{
			arg3 = get_arg_reg(war, pos);
			if (arg3 >= 1 && arg3 <= 16)
			{
				arg3 = crg->reg[arg3];
			}
			pos += 1;
		}
		else
		{
			arg3 = get_arg_dir(war, pos, 2);
			pos += 2;
		}
		// printf("arg2 = %d  arg 3 = %d\n", arg2, arg3);
		i = 0;
		// ft_print_1(war);
		// printf("pos = %d\n", GG(crg->pos + (arg2 + arg3) % IDX_MOD + i));
		while (i < 4)
		{
			war->arena[GG(crg->pos + (arg2 + arg3) % IDX_MOD + i)].code = (crg->reg[reg] >> (8 * (3 - i))) & 255;
			// printf("i = %d  arg = %d      ", i, (crg->reg[reg] >> (8 * (3 - i))) & 255);
			war->arena[GG(crg->pos + (arg2 + arg3) % IDX_MOD + i)].color = crg->player;
			i++;
		}
		// ft_print_1(war);
		// exit(1);


		
		// if (war->sti_count < 60)
		// {
		// 	printf("\n%d\n", pos - crg->pos);
		// 	war->sti_count++;
		// }
		ft_move_crg(war, crg, pos - crg->pos);
	}
}
