/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:18:24 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/09 15:23:51 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"


void	ft_init_ncurses(void) //прочитать документацию
{
	initscr();
	keypad(stdscr, true);// doc
	nodelay(stdscr, true);//doc
	curs_set(false);
	cbreak();
	noecho();
	start_color();
	init_color(COLOR_WHITE, 220, 220, 220);
	init_pair(0, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
	init_pair(13, COLOR_BLACK, COLOR_GREEN);
	init_pair(14, COLOR_GREEN, COLOR_BLACK);
}

void	ft_print_1(t_war *war, int *speed) // SOLO START!
{
	int i;
	

	i = 0;

	*speed = 1000; // Скорость движения кареток
	erase();

	while (i < MEM_SIZE)
	{
		if (war->arena[i].busy > 0)
		{
			attron(COLOR_PAIR(war->arena[i].crg_clr + 6));
			printw("%02x", 255 & war->arena[i].code);
			attroff(COLOR_PAIR(war->arena[i].crg_clr + 6));
		}
		else
		{
			attron(COLOR_PAIR(war->arena[i].color));
			printw("%02x", 255 & war->arena[i].code);
			attroff(COLOR_PAIR(war->arena[i].color));
		}
		printw(" ");
		if ((i + 1) % (64) == 0)
			printw("\n");
		i++;
	}
	attron(COLOR_PAIR(3));
	printw("Lives = %d  Cycle = %d  All-Cycles = %d Cycle-to-Dye = %d Numb crg = %d", war->live, war->cycle, war->all_cycle, war->to_die, war->numb_crg);
	attroff(COLOR_PAIR(3));
	refresh();
	usleep(1000);
	
	usleep(1000);

}

void	ft_print_arena(t_war *war)
{
	int a;
	int begin;

	begin = 0;
	a = 0;
	// ft_printf("0x%04x : ", begin);
	while (a < MEM_SIZE)
	{
		if (a % 64 == 0)
		{
			if (a != 0)
				write(1, "\n", 1);
			if (a < MEM_SIZE - 1)
				ft_printf("0x%04x : ", begin);
			begin += 64;
		}
		ft_printf("%02x", 255 & war->arena[a].code);	
		write(1, " ", 1);
		a++;
	}
	write(1, "\n", 1);
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

