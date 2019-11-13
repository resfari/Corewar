/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:29 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/12 15:15:31 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

//create 2 static massive. Its need for good order, cause if in argv we have flag -n 
//priority max lvl
void	ft_reserve_num_for_players(t_war *war)
{
	int i;

	i = 1;
	while (i < 5)
	{
		war->reserved_num[i] = 0; //for flags
		war->reserved_wo_n[i] = 0; //w.o flags
		i++;
	}
}

void	ft_init_arena(t_war *war)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		war->arena[i].code = 0;
		war->field[i] = '\0';
		i++;
	}
}

void	ft_init_main(t_war *war, char **argv, int argc)
{
	war->argv = argv;
	war->argc = argc;
	war->cycle = 0;
	war->live = 0;
	war->uniq = 0;
	war->all_cycle = 0;
	war->to_die = CYCLE_TO_DIE;
	war->numb_players = 0;
	war->check_num = 0;
	ft_reserve_num_for_players(war);
	ft_init_arena(war);
	ft_init_opp(war);
}
