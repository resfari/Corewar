/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:07:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/06 21:00:07 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"

int		ft_calc_bytes_to_skip(int *mass, int dir_size, int len)
{
	int i;
	int bytes;

	i = 0;
	bytes = 0;
	while (i < len)
	{
		if (mass[i] == 3)
			bytes += 1;
		else if (mass[i] == 5)
			bytes += dir_size;
		else if (mass[i] == 7)
			bytes += 2;
		i++;
	}
	return (bytes);
}

int	*ft_read_one_byte_for_arg(t_war *war, int num)
{
	char *str;
	unsigned char *ptr;
	int d;
	int res[3];
	int byte;
	int correct;
	int i;
	
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	d = 0;
	str = war->player[num].code;
	ptr = (unsigned char*)&(str[1]);
	byte = 7;
	i = 0;
	while (byte > 1)
	{
		correct = 1;
		if (ptr[d] & 1 << byte)
		{
			res[i] = 5;
			correct = 0;
		}
		byte--;
		if (ptr[d] & 1 << byte)
		{
			res[i] += 2 + correct;
		}
		i++;
		byte--;
	}
	return (res);
}

int		ft_check_argument(t_war *war, t_crg *crg, int oper)
{
	int i;
	int *res;

	i = 0;
	res = ft_read_one_byte_for_arg(war, crg->player);
	while (i < war->opp[oper].arg_len)
	{
		if (res[i] == 0 || war->opp[oper].types[i] % res[i] != 0)
		{
			crg->bytes_to_go = ft_calc_bytes_to_skip(res, war->opp[oper].dir_size, war->opp[oper].arg_len);
			return (0);
		}
		i++;
	}
	crg->bytes_to_go = ft_calc_bytes_to_skip(res, war->opp[oper].dir_size, war->opp[oper].arg_len);
	return (1);
}
