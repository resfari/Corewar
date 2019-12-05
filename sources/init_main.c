/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:29 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/05 17:50:56 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i++;
	}
}

void	ft_init_main(t_war *war, char **argv, int argc)
{
	war->argv = argv;
	war->argc = argc;
	war->to_die = CYCLE_TO_DIE;
	
	// ft_reserve_num_for_players(war);
	//ft_init_arena(war);
	ft_init_opp(war);


	//test params
	// war->zjmp_count = 0;
	// war->fork_count = 0;
	// war->sti_count = 0;
	// war->st_count = 0;
	// war->ld_count = 0;
	// war->live_count = 0;
}
