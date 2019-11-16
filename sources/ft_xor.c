/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:11:09 by pnita             #+#    #+#             */
/*   Updated: 2019/11/16 16:14:49 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_xor(t_war *war, t_crg *crg)
{
    int pos;
    int new_pos;
    int tmp_arg;
    int bit_xor_arg1_2;

    pos = crg->pos + 2;
    // get value from arg1
    if (crg->args[0] == 3)
    {
        tmp_arg = war->arena[GG(pos)].code;
        if (tmp_arg >= 1 && tmp_arg <= 16)
        {
            bit_xor_arg1_2 = crg->reg[tmp_arg];
        }
        pos += 1;
    }
    else if (crg->args[0] == 5)
    {
        tmp_arg = ((war->arena[GG(pos)].code) << 24 | (war->arena[GG(pos + 1)].code) << 16 |
	        (war->arena[GG(pos + 2)].code) << 8 | (war->arena[GG(pos + 3)].code));
        bit_xor_arg1_2 = tmp_arg;
        pos += 4;
    }
    else
    {
        tmp_arg = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
        new_pos = pos + tmp_arg % IDX_MOD;
        tmp_arg = ((war->arena[GG(new_pos)].code) << 24 | (war->arena[GG(new_pos + 1)].code) << 16 |
	        (war->arena[GG(new_pos + 2)].code) << 8 | (war->arena[GG(new_pos + 3)].code));
        bit_xor_arg1_2 = tmp_arg;
        pos += 2;
    }
    // get value from arg2
    if (crg->args[1] == 3)
    {
        tmp_arg = war->arena[GG(pos)].code;
        if (tmp_arg >= 1 && tmp_arg <= 16)
        {
            bit_xor_arg1_2 = bit_xor_arg1_2 ^ crg->reg[tmp_arg];
        }
        pos += 1;
    }
    else if (crg->args[0] == 5)
    {
        tmp_arg = ((war->arena[GG(pos)].code) << 24 | (war->arena[GG(pos + 1)].code) << 16 |
	        (war->arena[GG(pos + 2)].code) << 8 | (war->arena[GG(pos + 3)].code));
        bit_xor_arg1_2 = bit_xor_arg1_2 ^ tmp_arg;
        pos += 4;
    }
    else
    {
        tmp_arg = ((war->arena[GG(pos)].code) << 8 | (war->arena[GG(pos + 1)].code));
        new_pos = pos + tmp_arg % IDX_MOD;
        tmp_arg = ((war->arena[GG(new_pos)].code) << 24 | (war->arena[GG(new_pos + 1)].code) << 16 |
	        (war->arena[GG(new_pos + 2)].code) << 8 | (war->arena[GG(new_pos + 3)].code));
        bit_xor_arg1_2 = bit_xor_arg1_2 ^ tmp_arg;
        pos += 2;
    }
    // get arg3 and put bit_xor in it
    tmp_arg = war->arena[GG(pos)].code;
    if (tmp_arg >= 1 && tmp_arg <= 16)
    {
        crg->reg[tmp_arg] = bit_xor_arg1_2;
        if (crg->reg[tmp_arg] == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
    }
	ft_andor_calc_move(war, crg);
}
