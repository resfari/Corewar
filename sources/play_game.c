/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/12 20:23:15 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_init_first_cycle(t_war *war)
{
	t_crg *help;
	int opp;

	help = war->top;
	while (help)
	{
		opp = (int)(war->arena[help->pos].code & 255);
		// printf("\ninit opp in start = %d\n", opp);
		if (opp > 0 && opp < 17)
		{
			help->to_do = war->opp[opp].cycle;
			help->op = opp;
		}
		else
		{
			help->to_do = 0;
			help->op = -1;
		}
		war->arena[help->pos].crg_clr = help->player;
		war->arena[help->pos].busy = 1;
		help = help->next;
	}
}

int	ft_check_live_crg(t_war *war)
{
	t_crg *help;

	help = war->top;
	war->numb_crg = 0;
	while (help)
	{
		if (help->live == 0)
		{
			war->arena[GG(help->pos)].busy = 0;
			war->arena[GG(help->pos)].crg_clr = 0;
			help->die = 1;
		}
		if (help->die == 0)
		{
			help->live = 0;
			war->numb_crg++;
		}
		help = help->next;
	}
	return (war->numb_crg);
}

void	ft_play_game(t_war *war)
{
	// t_crg *help;
	// int speed;

	// //init first round, to_do count operation etc
	// speed = 10000;

	(void)war;
	// ft_init_first_cycle(war);
	// if (war->need_to_draw == 1)
	// 	ft_init_ncurses();
	initscr();                 // Инициализация ncurses
    curs_set(0);               // Делаем курсор невидимым
    printw("Hello, World!");   // Вывод строки Hello, World!
    refresh();                 // Отображение строки на реальном экране
    getch();                   // Ожидание пользовательского ввода
    endwin();  





	// if (getch() == ' '){
	// 	ft_init_ncurses();
	// 		ft_print_1(war); //добавление скорости не через структуру

	// }


	// while (1)
	// {
	// 	help = war->top;
	// 	ft_check_status_of_crg(war, help);
	// 	if (war->to_die <= 0)
	// 	{
	// 			ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
	// 			exit(1);
	// 	}

	// 	if (war->cycle == war->to_die)
	// 	{
	// 		war->check_num++;
	// 		if (ft_check_live_crg(war) == 0) // someone alive and kill no life crg
	// 		{
	// 			ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
	// 			exit(1);
	// 		}
	// 		if (war->check_num == 10 || war->live >= NBR_LIVE)
	// 		{
	// 			war->to_die -= CYCLE_DELTA;
	// 			war->check_num = 0;
	// 		}
	// 		war->cycle = 0;
	// 		war->live = 0;
	// 	}

	// 	if (war->dump == 1 && war->dump_cycle == war->all_cycle)
	// 	{
	// 		ft_print_arena(war);
	// 		ft_free_exit(war, 0); // No error
	// 	}

	// 	if (war->need_to_draw == 1)
	// 	{
	// 		ft_print_1(war); //добавление скорости не через структуру
	// 		usleep(1000);
	// 	}
	// 	war->cycle++;
	// 	war->all_cycle++;
	// }

	
	// ft_printf("Contestant %d, \"%s\", has won !\n", war->winner, war->player[war->winner].name);
	// exit(1);
}
