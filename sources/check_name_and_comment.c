/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:18:15 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/02 20:08:09 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_check_chars(int is_valid, int cases) //check this later like b.r.a
{
	if (cases == 0)
	{
		if ((is_valid >= 65 && is_valid <= 90) ||
		(is_valid >= 97 && is_valid <= 122) ||
		(is_valid >= 42 && is_valid <= 57) ||
		is_valid == 32 || is_valid == 39 || is_valid == 61 || is_valid == 33 || is_valid == 0
		|| is_valid == 95)
		{
			return (1);
		}
		ft_printf("\nError Name, %d\n", is_valid);
		return (0);
	}
	if (cases == 1)
	{
		if ((is_valid >= 65 && is_valid <= 90) ||
		(is_valid >= 97 && is_valid <= 122) ||
		(is_valid >= 39 && is_valid <= 57) ||
		is_valid == 32 || is_valid == 61 || is_valid == 63 ||
		is_valid == 33 || is_valid == 0 || is_valid == 33 || is_valid == 58 ||
		is_valid == 10 || is_valid == -27 || is_valid == -29 || is_valid == -61)
		{
			return (1);
		}
		ft_printf("\nError Comment, %d\n", is_valid);
		return (0);
	}
	return (0);
}

void	ft_check_name(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 4;
	while (i < PROG_NAME_LENGTH)
	{
		// if (ft_check_chars(war->player[num].text[j], 0) == 0)
		// {
		// 	ft_free_exit(war, 8);
		// }
		war->player[num].name[i] = war->player[num].text[j];
		i++;
		j++;
	}
}

void	ft_check_comment(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 12 + PROG_NAME_LENGTH;
	while (i < COMMENT_LENGTH)
	{
		// if (ft_check_chars(war->player[num].text[j], 1) == 0)
		// {
		// 	ft_free_exit(war, 8);
		// }
		war->player[num].comment[i] = war->player[num].text[j];
		i++;
		j++;
	}
}
