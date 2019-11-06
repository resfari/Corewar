/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_crg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:11:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/05 19:31:12 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"


t_crg	*ft_create_crg(t_war *war, int num)
{
	t_crg *new;

	if (!(new = (t_crg*)malloc(sizeof(t_crg) * 1)))
		ft_free_exit(war, 1);
	new->next = NULL;
	new->prev = NULL;
	new->player = num;
	new->carry = 0;
	new->uniq_num = war->uniq;
	war->uniq++;
	new->die = 0;
	new->cycle_to_die = CYCLE_TO_DIE;
	new->pos = war->player[num].start_pos;
	new = ft_init_reg_in_crg(new, num);
	return (new);
}

t_crg	*ft_add_crg(t_war *war, t_crg *crg, int num)
{
	t_crg *help;

	help = crg;
	while (help && help->next)
	{
		help = help->next;
	}
	help->next = ft_create_crg(war, num);
	help->next->prev = help;
	return (help->next);
}

void	ft_fill_crg(t_war *war)
{
	int		i;
	t_crg	*crg;

	i = war->numb_players;
	crg = NULL;
	war->winner = i; //initialize winner(start from max identification number)
	while (i >= 1)
	{
		if (crg == NULL)
		{
			crg = ft_create_crg(war, i);
			war->top = crg;
		}
		else
		{
			war->bot = ft_add_crg(war, crg, i);
		}
		i--;
	}
	if (war->numb_players == 1)
		war->bot = crg;
}
