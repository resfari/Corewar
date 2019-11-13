/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:32 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/03 18:13:47 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

int     ft_add_player_wo_number(t_war *war, int i)
{
	int j;

	j = 1;
	if (i > war->argc - 1)
	{
		ft_putstr("Check players");
		exit(1);
	}
	while (j < 5)
	{
		if (war->reserved_wo_n[j] == 0)
		{
			war->reserved_wo_n[j] = i;
			war->numb_players++;
			return (i);
		}
		j++;
	}
	ft_putstr("Check players");
	exit(1);
}

int     ft_add_player_with_number(t_war *war, int i)
{
	int num;

	if (i > war->argc - 1)
	{
		ft_putstr("Check players");
		exit(1);
	}
	if ((num = ft_check_valid_num(war, war->argv[i])) == 0)
	{
		ft_putstr("Check players");
		exit(1);
	}
	if (ft_check_free_num(war, num) == 0)
	{
		ft_putstr("Check players");
		exit(1);
	}
	war->player[num].path = war->argv[i + 1];
	return (i + 1);
}

void    ft_read_flags_players(t_war *war)
{
	int i;
	int file;

	file = 0;
	i = 1;
	while (i < war->argc)
	{
		if (ft_strequ(war->argv[i], "-n"))
		{
			i = ft_add_player_with_number(war, i + 1);
		}
		else
		{
			i = ft_add_player_wo_number(war, i);
		}
		i++;
	}
	close(file);
	if (ft_check_order_amount_players(war) == 0)
	{
		ft_putstr("Check players order");
		exit(1);
	}
}