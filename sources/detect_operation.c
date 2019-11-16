/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:39:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 20:53:58 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_detect_operation(int op_num, t_war *war, t_crg *crg)
{
	printf("\nnumb of operation = %d\n", op_num);
	if (op_num == 1)
	{
		// printf("pos = %d\n",crg->pos);
		ft_live(war, crg);
	}
	else if (op_num == 2)
	{
		ft_ld(war, crg, 0);
	}
	else if (op_num == 3)
	{
		ft_st(war, crg);
	}
	else if (op_num == 4)
	{
		ft_add(war, crg);
	}
	else if (op_num == 5)
	{
		ft_sub(war, crg);
	}
	else if (op_num == 6)
	{
		ft_and(war, crg);
	}
	else if (op_num == 7)
	{
		ft_or(war, crg);
	}
	else if (op_num == 8)
	{
		ft_xor(war, crg);
	}
	else if (op_num == 9)
	{
		ft_zjmp(war, crg);
	}
	else if (op_num == 10)
	{
		ft_ldi(war, crg, 0);
	}
	else if (op_num == 11)
	{
		ft_sti(war, crg);
	}
	else if (op_num == 12)
	{
		ft_fork(war, crg, 0);
	}
	else if (op_num == 13)
	{
		ft_ld(war, crg, 1); // case == 1 cause its same opperation
	}
	else if (op_num == 14)
	{
		ft_ldi(war, crg, 1);
	}
	else if (op_num == 15)
	{
		ft_fork(war, crg, 1);
	}
}
