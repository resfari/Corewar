/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_of_crg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:30:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/19 21:28:25 by lgeorgia         ###   ########.fr       */
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
		crg->op = war->arena[GG(crg->pos)].code & 255;
		if (crg->moved == 1)
		{
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
				// printf("\nno skip\n");
				ft_detect_operation(crg->op, war, crg); // detect and do it
			}
			else
			{
				// printf("\nskip cause bad arg\n");
				ft_move_crg(war, crg, crg->bytes_to_go);
			}
			crg->moved = 1;
		}
	}
}

void	ft_check_status_of_crg(t_war *war, t_crg *crg)
{
	t_crg *help;
	int numb_crg;

	numb_crg = 0;
	(void)crg;
	help = war->top;
	// printf("numb = %d\n", war->test_numb);
	while (help)
	{
		if (help->die == 0)
		{
			numb_crg++;
			ft_check_one_crg(war, help); // upd: NO need to add check of busy status
		}
		help = help->next;
	}
	// printf("NUMB= %d ", numb_crg);
}
