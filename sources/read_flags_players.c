/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:32 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/22 18:47:04 by lgeorgia         ###   ########.fr       */
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
		if (i == 1 && ft_strequ(war->argv[1], "-v"))
		{
			war->need_to_draw = 1;
		}
		else if (i == 1 && ft_strequ(war->argv[1], "-dump"))
		{
			if (i + 1 < war->argc)
			{
				ft_take_dump(war, i + 1);
				war->dump = 1;
				i += 1;
			}
			else
			{
				ft_free_exit(war, 6);
			}
			
		}
		else
		{
			ft_putnbr(i);
			if (ft_strequ(war->argv[i], "-n"))
			{
				i = ft_add_player_with_number(war, i + 1);
			}
			else
			{
				i = ft_add_player_wo_number(war, i);
			}
		}
		i++;
	}
	write(1, "\nERROR\n", 7);
	close(file);
	if (ft_check_order_amount_players(war) == 0)
	{
		ft_putstr("Check players order");
		exit(1);
	}
	printf("players = %d dump flag = %d\n", war->numb_players, war->dump);
}