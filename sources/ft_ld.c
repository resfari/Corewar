/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:34 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/14 17:13:22 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

void	ft_ld_dir(t_war *war, t_crg *crg)
{
	int arg;
	int pos;
	int reg;

	pos = crg->pos + 2;

	arg = ((255 & war->arena[GG(pos)].code) << 24 | (255 & war->arena[GG(pos + 1)].code) << 16 |
	(255 & war->arena[GG(pos + 2)].code) << 8 | (255 & war->arena[GG(pos + 3)].code));
	reg = war->arena[GG(pos + 4)].code;
	printf("\nregistr = %d\n", reg);
	exit(1);
}


void	ft_ld(t_war *war, t_crg *crg)
{
	printf("\narg = %d\n", crg->args[0]);
	if (crg->args[0] == 5) // first arg == T_DIR
	{
		ft_ld_dir(war, crg);
	}
}
