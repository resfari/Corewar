/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:18:24 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/17 15:43:54 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_init_ncurses(void)
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
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

void	ft_print_1_part1(t_war *war, int i)
{
	if (war->arena[i].busy > 0)
	{
		attron(COLOR_PAIR(war->arena[i].crg_clr + 6));
		printw("%02x", war->arena[i].code);
		attroff(COLOR_PAIR(war->arena[i].crg_clr + 6));
	}
	else
	{
		attron(COLOR_PAIR(war->arena[i].color));
		printw("%02x", war->arena[i].code);
		attroff(COLOR_PAIR(war->arena[i].color));
	}
}

void	ft_print_1(t_war *war, int winner)
{
	int i;

	i = 0;
	erase();
	while (i < MEM_SIZE)
	{
		if (i != 0 && (i % (64) == 0))
			printw("\n");
		ft_print_1_part1(war, i);
		printw(" ");
		i++;
	}
	attron(COLOR_PAIR(3));
	printw("\n");
	printw("Lives = %d  Cycle = %d  All-Cycles = %d "
			"Cycle-to-Dye = %d Numb crg = %d",
			war->live, war->cycle, war->all_cycle, war->to_die, war->numb_crg);
	if (winner == 1)
		printw("\nWinner is %s\n", war->player[war->winner].name);
	attroff(COLOR_PAIR(3));
	refresh();
}

void	ft_print_arena(t_war *war)
{
	int a;
	int begin;
	int oct;

	oct = 64;
	if (war->dump2 == 1)
		oct = 32;
	begin = 0;
	a = 0;
	while (a < MEM_SIZE)
	{
		if (a % oct == 0)
		{
			if (a != 0)
				write(1, "\n", 1);
			if (a < MEM_SIZE - 1)
				ft_printf("0x%04x : ", begin);
			begin += oct;
		}
		ft_printf("%02x", war->arena[a].code);
		write(1, " ", 1);
		a++;
	}
	write(1, "\n", 1);
}
