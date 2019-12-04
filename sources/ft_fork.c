/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:37:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/04 18:51:53 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_add_in_list_crg(t_war *war, t_crg *new)
{
	new->next = war->top;
	war->top = new;
}

void	ft_copy_reg(t_crg *new, t_crg *crg)
{
	int i;

	i = 1;
	while (i <= 16)
	{
		new->reg[i] = crg->reg[i];
		i++;
	}
}

void	ft_add_new_crg(t_war *war, t_crg *crg, int pos)
{
	t_crg *new;

	new = ft_create_crg(war, crg->player);
	// if (war->arena[pos].busy == 0)
	// {
	// 	war->arena[pos].busy = 1;
	// 	war->arena[pos].crg_clr = crg->player;
	// }
	// else
	// {
	// 	war->arena[pos].busy += 1;
	// }
	new->pos = crg->pos;
	new->live = crg->live;
	new->carry = crg->carry;
	new->moved = 1;
	new->to_do = 0;
	ft_copy_reg(new, crg);
	ft_add_in_list_crg(war, new);
	ft_move_crg(war, new, pos);
}

void	ft_fork(t_war *war, t_crg *crg, int cases)
{
	int arg;
	int pos;
	int	new_pos;

	pos = crg->pos + 1;
	arg = get_arg_dir(war, pos, 2);
	// if (war->all_cycle < 2500)
	// 	printf("\n%d FORK: addr = %d\n", cases, arg);
	// printf("\nfOrk DIR = %d\n", arg);
	if (cases == 0) // fork
	{
		new_pos = arg % IDX_MOD;
		// if (war->fork_count < 20)
		// {
		// 	printf("\n Fork new pos = %d\n", new_pos);
		// 	war->fork_count++;
		// }
		// else
		// 	exit(1);
	}
	else // lfork
	{
		new_pos = arg;
	}
	ft_add_new_crg(war, crg, new_pos);
	ft_move_crg(war, crg, 3);
	war->fork_count++;
}
