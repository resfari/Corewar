/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:37:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/16 18:54:00 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"


int		ft_arg_fork(war, crg, pos)
{

}

void	ft_fork(t_war *war, t_crg *crg)
{
	int arg;
	int pos;

	pos = crg->pos + 1;
	arg = ((war->arena[GG(pos)].code) << 24 | (war->arena[GG(pos + 1)].code) << 16 |
	(war->arena[GG(pos + 2)].code) << 8 | (war->arena[GG(pos + 3)].code));
	


}
