/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:39:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/14 16:07:51 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

void	ft_detect_operation(int op_num, t_war *war, t_crg *crg)
{
	if (op_num == 1)
	{
		// printf("pos = %d\n",crg->pos);

		ft_live(war, crg);
	}
	if (op_num == 2)
	{
		ft_ld(war, crg);
	}
}
