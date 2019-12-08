/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:32 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 17:08:41 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_take_dump(t_war *war, int index)
{
	unsigned int res;
	int i;
	char *line;

	i = 0;
	res = 0;
	line = war->argv[index];
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57)
		{
			res = res * 10 + line[i] - 48;
		}
		else
		{
			ft_free_exit(war, 10);
		}
		i++;
	}
	if (i > 10 || res > 2147483647)
	{
		ft_free_exit(war, 10);
	}
	war->dump_cycle = (int)res;
}

int     ft_add_player_wo_number(t_war *war, int i)
{
	int j;

	j = 1;
	if (i > war->argc - 1)
	{
		ft_free_exit(war, 4);
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
	ft_free_exit(war, 4);
	return (0);
}

int     ft_add_player_with_number(t_war *war, int i)
{
	int num;

	if ((num = ft_check_valid_num(war, war->argv[i])) == 0)
	{
		ft_free_exit(war, 4);
	}
	if (ft_check_free_num(war, num) == 0)
	{
		ft_free_exit(war, 4);
	}
	war->player[num].path = war->argv[i + 1];
	return (i + 1);
}

void    ft_read_flags_players(t_war *war)
{
	int i;

	i = 1;
	while (i < war->argc)
	{
		if (ft_strequ(war->argv[i], "-v")) // if several times -v?
		{
			war->need_to_draw = 1;
		}
		else if (ft_strequ(war->argv[1], "-help")) // if -help and smth else (-v -help) or several times -help?
		{
			ft_free_exit(war, 11);
		}
		else if (ft_strequ(war->argv[i], "-dump"))
		{
			if (war->dump == 1 || i + 1 >= war->argc || war->dump2 == 1)
			{
				ft_free_exit(war, 5);
			}
			if (i + 1 < war->argc)
			{
				ft_take_dump(war, i + 1);
				war->dump = 1;
				i += 1;
			}
		}
		else if (ft_strequ(war->argv[i], "-live")) // if several times -live?
		{
			war->vis_live = 1;
		}
		else if (ft_strequ(war->argv[i], "-a")) // if several times -a?
		{
			war->aff = 1;
		}
		else if (ft_strequ(war->argv[i], "-d32"))
		{
			if (war->dump == 1 || i + 1 >= war->argc || war->dump2 == 1)
			{
				ft_free_exit(war, 5);
			}
			if (i + 1 < war->argc)
			{
				ft_take_dump(war, i + 1);
				war->dump2 = 1;
				i += 1;
			}
		}
		else
		{
			if (ft_strequ(war->argv[i], "-n"))
			{
				if (i + 2 >= war->argc)
				{
					ft_free_exit(war, 4);
				}
				i = ft_add_player_with_number(war, i + 1);
			}
			else
			{
				i = ft_add_player_wo_number(war, i);
			}
		}
		i++;
	}
	if (ft_check_order_amount_players(war) == 0)
	{
		ft_free_exit(war, 4);
	}
}