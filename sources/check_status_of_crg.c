/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_of_crg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:30:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/04 17:31:17 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_check_one_crg(t_war *war, t_crg *crg)
{
	if (crg->to_do > 0)
	{
		crg->to_do--;
		// printf("%d\n", crg->to_do);
	}
	else
	{
		if (crg->moved == 1)
		{
			crg->op = get_arg_reg(war, crg->pos);
			if (crg->op >= 1 && crg->op <= 16) // valid operation
			{
				// printf("\nGOOD OPP = %d\n", crg->op);
				crg->to_do = war->opp[crg->op].cycle - 2; // init cycles for to_do opperation
				crg->moved = 0;
			}
			else // if not-valid opperation
			{
				// printf("\nSKIP OPP = %d\n", crg->op);
				crg->to_do = 0;
				ft_move_crg(war, crg, 1);
				crg->moved = 1;
			}
		}
		else if (crg->to_do == 0)
		{
			if (crg->op == 1 || crg->op == 9 || crg->op == 12 || crg->op == 15 ||
			ft_check_argument(war, crg, crg->op) == 1) // assign bytes to skip
			{
				ft_detect_operation(crg->op, war, crg); // detect and do it
			}
			else
			{
				// if (war->all_cycle >= 7195 && war->all_cycle <= 7196)
				// {
					
				// 	printf("here2\n");
				// }
				// if (war->all_cycle > 1729 && war->all_cycle < 1731)
				// 	printf("skip cause bad arg\n");
				ft_move_crg(war, crg, crg->bytes_to_go);
			}
			crg->moved = 1;
		}
	}
}

void	ft_check_status_of_crg(t_war *war, t_crg *crg)
{
	t_crg *help;

	// war->numb_crg = 0;
	(void)crg;
	help = war->top;
	// printf("numb = %d\n", war->test_numb);
	while (help)
	{
		if (help->die == 0)
		{
			ft_check_one_crg(war, help); // upd: NO need to add check of busy status
		}
		help = help->next;
	}
	// printf("NUMB= %d ", numb_crg);
}
