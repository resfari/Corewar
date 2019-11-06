/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/06 16:11:00 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"

int	ft_check_live_crg(t_war *war)
{
	t_crg *help;

	help = war->top;
	war->numb_crg = 0;
	while (help)
	{
		if (help->cycle_of_live >= CYCLE_TO_DIE || help->cycle_to_die <= 0)
		{
			help->die = 1;
		}
		if (help->die == 0)
		{
			war->numb_crg++;
		}
		help = help->next;
	}
	return (war->numb_crg);
}

void	ft_play_game(t_war *war)
{
	t_crg *help;

	//init first round, to_do count operation etc
	while (1)
	{
		help = war->top;
		if (ft_check_live_crg(war) == 0)
		{
			ft_putstr("Winner is ???\n");
			exit(1);
		}
		else
		{
			ft_check_status_of_crg(war, help);
		}
		war->cycle++;
		war->cycle_to_die--;
	}
}
