/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompose_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:23:24 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/04 16:41:45 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

//mb need to add check size of code by reading CHAMPION NAME SIZE + 8 --4bytes
void	ft_decompose(t_war *war, int num)
{
	ft_check_magic(war, num);
	ft_check_name(war, num);
	ft_check_comment(war, num);
	ft_check_code(war, num);
}

void	ft_decompose_pl_code(t_war *war)
{
	int i;

	i = 1;
	while (i <= war->numb_players)
	{
		ft_decompose(war, i);
		i++;
	}
}
