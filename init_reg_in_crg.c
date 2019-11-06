/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reg_in_crg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:27:04 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/05 17:01:42 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"

t_crg	*ft_init_reg_in_crg(t_crg *crg, int num)
{
	int i;

	i = 1;
	crg->reg[0] = -1 * num;
	while (i < REG_NUMBER)
	{
		crg->reg[i] = 0;
		i++;
	}
	return (crg);
}
