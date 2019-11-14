/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:05:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/05 17:14:34 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_greatings(t_war *war)
{
	int i;

	i = 1;
	while (i <= war->numb_players)
	{
		ft_putstr("* Player ");
		ft_putnbr(i);
		ft_putstr(", weighing ");
		ft_putnbr(war->player[i].code_len);
		ft_putstr(" bytes,  \"");
		ft_putstr(war->player[i].name);
		ft_putstr("\" (\"");
		ft_putstr(war->player[i].comment);
		ft_putstr("\") !\n");
		i++;
	}
}
