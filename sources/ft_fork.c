/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:37:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/18 20:32:07 by lgeorgia         ###   ########.fr       */
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
	if (war->arena[pos].busy == 0)
	{
		war->arena[pos].busy = 1;
		war->arena[pos].crg_clr = crg->player;
	}
	else
	{
		war->arena[pos].busy += 1;
	}
	new->pos = pos;
	new->live = crg->live;
	new->carry = crg->carry;
	new->moved = 1;
	new->to_do = 0;
	ft_copy_reg(new, crg);
	ft_add_in_list_crg(war, new);
}

void	ft_fork(t_war *war, t_crg *crg, int cases)
{
	int arg;
	int pos;
	int	new_pos;

	pos = crg->pos + 1;
	arg = get_arg_dir(war, pos, 2);
	if (cases == 0) // fork
		new_pos = GG((int)arg % IDX_MOD);
	else // lfork
	{
		new_pos = GG(crg->pos + (int)arg);
	}
	ft_add_new_crg(war, crg, new_pos);
	ft_move_crg(war, crg, 3);
}
