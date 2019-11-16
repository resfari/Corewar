/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:00:07 by pnita             #+#    #+#             */
/*   Updated: 2019/11/16 20:24:43 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int get_arg_reg(t_war *war, int pos)
{
	return war->arena[GG(pos)].code;
}

int get_arg_dir(t_war *war, int pos, int size)
{
	if (size == 2)
	{
		return ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
	}
	return ((war->arena[GG(pos)].code) << 24 | (war->arena[GG(pos + 1)].code) << 16 |
		(war->arena[GG(pos + 2)].code) << 8 | (war->arena[GG(pos + 3)].code));
}

int get_arg_ind(t_war *war, int pos)
{
	return ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
}
