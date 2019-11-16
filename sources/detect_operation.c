/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:39:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 17:28:09 by lgeorgia         ###   ########.fr       */
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
		ft_ld(war, crg);
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
		ft_ldi(war, crg);
	}
	else if (op_num == 11)
	{
		ft_sti(war, crg);
	}
}
