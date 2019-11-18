/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:18:24 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/18 16:23:02 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"



void	ft_print(t_war *war)
{
	int i;

	i = 0;
	erase();
	while (i < MEM_SIZE)
	{
		attron(COLOR_PAIR(war->arena[i].color));
		printw("02x", 255 & war->arena[i].code);
		attroff(COLOR_PAIR(war->arena[i].color));
		printw(" ");
		if ((i + 1) % (64) == 0)
			printw("\n");
		i++;
	}
	refresh();
}

// void	ft_print(t_war *war)
// {
// 	int i;
// 	int hex;

// 	hex = 0;
// 	i = 0;
// 	while (i < MEM_SIZE)
// 	{
// 		// if ((i) % (64) == 0)
// 		// 	printf("0x%04x :", hex);
// 		printf("%02x ", 255 & war->arena[i].code);
// 		if ((i + 1) % (32) == 0)
// 		{
// 			printf("\n");
// 		}
// 		i++;
// 	}
// 	exit(1);
// }

