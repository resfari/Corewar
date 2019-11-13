/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:22:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/12 18:49:16 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

void	ft_move_crg(t_war *war, t_crg *crg, int move)
{
	(void)war;

	crg->pos += move;
	crg->pos = GG(crg->pos);
}