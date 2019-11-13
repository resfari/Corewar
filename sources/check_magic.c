/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic_comm_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:27:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/04 15:01:25 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

void		ft_compare_magic(t_war *war, char *magic)
{
	int i;

	i = 0;
	const char orig[32] = "11110011100000111110101000000000"; // binary for magic in .h file
	while (i < 32)
	{
		if (magic[i] != orig[i])
		{
			ft_free_exit(war, 7);
		}
		i++;
	}
}
//We read first 4 bytes from file to compare this orig. magic
// This func can be upgrade by optimize while(compare at once this 11110011100000111110101000000000)
// no need func ft_compare_magic
void	ft_check_magic(t_war *war, int num)
{
	char *str;
	unsigned char *ptr;
	char fin[33];
	int j;
	int d;
	int i;
	
	fin[32] = '\0';
	j = 31;
	d = 0;
	str = war->player[num].text;
	ptr = (unsigned char*)&(str[0]);
	while (d < 4)
	{
		i = 0;
		while (i < 8)
		{
			if (ptr[d] & 1 << i)
				fin[j] = '1';
			else
				fin[j] = '0';
			i++;
			j--;
		}
		d++;
	}
	ft_compare_magic(war, fin);
}
