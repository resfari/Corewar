/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:39:00 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/18 19:12:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_aff(t_war *war, t_crg *crg)
{
	char c;
	int pos;
	int reg;

	pos = GG(crg->pos + 1);
	reg = war->arena[pos].code;

	if (reg >= 1 && reg <= 16)
	{
		c = (char)crg->reg[reg];
		// printf("\nAFF CHAR = %d\n", c);
		write(1, &c, 1);
	}
	ft_move_crg(war, crg, 3);
}
