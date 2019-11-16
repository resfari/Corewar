/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:37:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 21:57:54 by lgeorgia         ###   ########.fr       */
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
	new->pos = pos;
	new->live = crg->live;
	new->carry = crg->carry;
	new->moved = 1;
	new->to_do = 0;
	ft_copy_reg(new, crg);
	ft_add_in_list_crg(war, new);
}

void	ft_add_new_crg_busy(t_war *war, t_crg *crg, int pos)
{
	t_crg *new;

	new = ft_create_crg(war, crg->player);
	new->queue_skip = pos;
	new->in_queue = 1;
	new->pos = crg->pos;
	war->arena[crg->pos].busy = 1;
	new->live = crg->live;
	new->carry = crg->carry;
	new->moved = 0;
	new->to_do = 0;
	ft_copy_reg(new, crg);
	ft_add_in_list_crg(war, new);
}

void	ft_fork(t_war *war, t_crg *crg, int cases)
{
	unsigned int arg;
	int pos;
	int	new_pos;

	war->test_numb++; //delete this shit
	pos = crg->pos + 1;
	arg = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
	if (cases == 0) // fork
		new_pos = GG((int)arg % IDX_MOD);
	else // lfork
	{
		new_pos = GG(crg->pos + arg);
	}
	if (war->arena[new_pos].busy == 0)
	{
		ft_add_new_crg(war, crg, new_pos);
	}
	else
	{
		ft_add_new_crg_busy(war, crg, new_pos);
	}
	ft_move_crg(war, crg, 5);
}
