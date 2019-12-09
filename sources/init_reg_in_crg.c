/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reg_in_crg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:27:04 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/22 19:56:12 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

t_crg	*ft_init_reg_in_crg(t_crg *crg, int num)
{
	int i;

	i = 2;
	crg->reg[1] = num * -1;
	while (i <= REG_NUMBER)
	{
		crg->reg[i] = 0;
		i++;
	}
	return (crg);
}