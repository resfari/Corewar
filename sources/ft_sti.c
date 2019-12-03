/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:38:07 by pnita             #+#    #+#             */
/*   Updated: 2019/12/03 18:55:12 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"


void	ft_move_sti_reg_error(t_war *war, t_crg *crg)
{
	int res;

	res = 3; // code, types of args, #3 arg T_REG
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
			// printf("\nSTI: arg1 = %d ", arg2);
			arg2 = get_arg_dir(war, crg->pos + arg2 % IDX_MOD, 4);
			// printf("STI: arg2 = %d  pos = %d  pos-crg = %d\n", arg2, pos + arg2 % IDX_MOD, crg->pos);
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
		// printf("arg2 = %d  arg 3 = %d\n", arg2, arg3);
		i = 0;
		// ft_print_1(war);
		// printf("pos = %d\n", GG(crg->pos + (arg2 + arg3) % IDX_MOD + i));
		while (i < 4)
		{
			// if (war->all_cycle == 20720)
			// {
				// printf("\npos = %d, code = %d, reg = %d, reg[reg] = %d\n", GG((crg->pos + (arg2 + arg3) % IDX_MOD + i)),
			// 	(crg->reg[reg] >> (8 * (3 - i))) & 255, reg, crg->reg[reg]);
			// 
			// ft_printf("\nSTI: = %d\n", GG(x));
			x = crg->pos + (arg2 + arg3) % IDX_MOD + i;
			war->arena[GG(x)].code = (crg->reg[reg] >> (8 * (3 - i))) & 255;
			// printf("i = %d  arg = %d      ", i, (crg->reg[reg] >> (8 * (3 - i))) & 255);
			war->arena[GG(x)].color = crg->player;
			i++;
		}
		// if (war->sti_count < 10)
		// {
		// 	printf("\nSTI: addr1 = %d addr2 = %d", arg2, arg3);
		// 	printf(" reg = %d value = %d addr = %d\n", reg, crg->reg[reg], crg->pos + (arg2 + arg3) % IDX_MOD);
		// 	war->sti_count++;
		// }
		
		ft_move_crg(war, crg, pos - crg->pos);
	}
	else
		ft_move_sti_reg_error(war, crg);
}
