/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:39 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/04 16:30:24 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_check_code(t_war *war, int num)
{
	int i;
	int j;

	j = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	i = 0;
	while (j < war->player[num].text_len)
	{
		war->player[num].code[i] = war->player[num].text[j];
		i++;
		j++;
	}
	war->player[num].code_len = j - (16 + PROG_NAME_LENGTH + COMMENT_LENGTH);
	if (war->player[num].code_len > CHAMP_MAX_SIZE)
		ft_free_exit(war, 9);
}
