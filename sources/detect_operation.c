/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:39:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/18 20:34:25 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_detect_operation(int op_num, t_war *war, t_crg *crg)
{
	if (op_num == 1)
	{
		// printf("pos = %d\n",crg->pos);
		ft_live(war, crg);
	}
	else if (op_num == 2)
	{
		// printf("LD\n");
		ft_ld(war, crg, 0);
	}
	else if (op_num == 3)
	{
		// printf("ST\n");
		ft_st(war, crg);
	}
	else if (op_num == 4)
	{
		// printf("ADD\n");
		ft_add(war, crg);
	}
	else if (op_num == 5)
	{
		// printf("SUB\n");
		ft_sub(war, crg);
	}
	else if (op_num == 6)
	{
		// printf("AND\n");
		ft_and(war, crg);
	}
	else if (op_num == 7)
	{
		// printf("OR\n");
		ft_or(war, crg);
	}
	else if (op_num == 8)
	{
		// printf("XOR\n");
		ft_xor(war, crg);
	}
	else if (op_num == 9)
	{
		// printf("ZJMP\n");
		ft_zjmp(war, crg);
	}
	else if (op_num == 10)
	{
		// printf("LDI\n");
		ft_ldi(war, crg, 0);
	}
	else if (op_num == 11)
	{
		// printf("STI\n");
		ft_sti(war, crg);
	}
	else if (op_num == 12)
	{
		// printf("FORK\n");
		ft_fork(war, crg, 0);
	}
	else if (op_num == 13)
	{
		// printf("LD\n");
		ft_ld(war, crg, 1); // case == 1 cause its same opperation
	}
	else if (op_num == 14)
	{
		// printf("LDI\n");
		ft_ldi(war, crg, 1);
	}
	else if (op_num == 15)
	{
		// printf("L__________________FORK\n");
		ft_fork(war, crg, 1);
	}
	else if (op_num == 16)
	{
		// printf("AFF\n");
		ft_aff(war, crg);
	}
}
