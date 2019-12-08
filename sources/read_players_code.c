/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_players_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:13 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 17:06:15 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_copy_code_in_player(t_war *war, int num)
{
	int file;
	int size;

	if ((file = open(war->player[num].path, O_RDONLY)) == -1) // what for we open and read again?
	{
		ft_free_exit(war, 3);
	}
	if ((size = read(file, war->player[num].text, war->player[num].text_len)) == -1)
	{
		ft_free_exit(war, 3);
	}
	war->player[num].text[war->player[num].text_len] = '\0';
	close(file);
	return (size);
}

int		ft_len_player_code(t_war *war, int num)
{
	char buf[BUFF_SIZE];
	int file;
	int size;

	if ((file = open(war->player[num].path, O_RDONLY)) == -1)
	{
		ft_free_exit(war, 3);
		exit(1);
	}
	war->player[num].text_len = 0;
	while ((size = read(file, buf, BUFF_SIZE)) > 0) // if file of player is empty?
	{
		if (size != 0)
			war->player[num].text_len += size;
	}
	if (war->player[num].text_len > MAX_CODE_SIZE + 16)
	{
		ft_free_exit(war, 9);
	}
	close(file);
	return (ft_copy_code_in_player(war, num));
}

void	ft_read_players_code(t_war *war)
{
	int i;

	i = 1;
	while (i <= war->numb_players)
	{
		
		war->player[i].text_len = ft_len_player_code(war, i);
		i++;
	}
}
