/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_of_crg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:30:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/06 21:20:13 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"

void	ft_check_one_crg(t_war *war, t_crg *crg)
{
	int is_op;

	if (crg->cycle_to_do == 0)
	{
		is_op = (int)((war->arena[crg->pos].code) & 255);
		if (is_op >= 1 && is_op <= 16)
		{
			if (is_op == 1 || is_op == 9 || is_op == 12 || is_op == 15 ||
			ft_check_argument(war, crg, is_op) == 1) // assign bytes to skip
			{
				ft_detect_operation(is_op, war, crg); // decect and do it
				return ;
			}	
		}
		else
		{
			crg->pos++;
			crg->cycle_to_do--;
			crg->cycle_to_die--;
		}
	}
	else
	{
		crg->cycle_to_do--;
		crg->cycle_to_die--;
	}
	
}

void	ft_check_status_of_crg(t_war *war, t_crg *crg)
{
	t_crg *help;

	help = war->top;
	while (help)
	{
		if (help->die == 0)
		{
			ft_check_one_crg(war, help);
		}
		if (help->next == war->top)
			return ;
		help = help->next;
	}
}
