/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:45:20 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/06 19:10:42 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "corewar.h"


void	ft_init_opp4(t_war *war)
{
	war->opp[12].arg_len = 1;
	war->opp[12].types[0] = 5;
	war->opp[12].dir_size = 2;
	war->opp[12].cycle = 800;
	
	war->opp[13].arg_len = 2;
	war->opp[13].types[0] = 35;
	war->opp[13].types[1] = 3;
	war->opp[13].dir_size = 4;
	war->opp[13].cycle = 10;

	war->opp[14].arg_len = 3;
	war->opp[14].types[0] = 105;
	war->opp[14].types[1] = 15;
	war->opp[14].types[2] = 3;
	war->opp[14].dir_size = 2;
	war->opp[14].cycle = 50;

	war->opp[15].arg_len = 1;
	war->opp[15].types[0] = 5;
	war->opp[15].dir_size = 2;
	war->opp[15].cycle = 1000;

	war->opp[16].arg_len = 1;
	war->opp[16].types[0] = 3;
	war->opp[16].dir_size = 4;
	war->opp[16].cycle = 2;
}

void	ft_init_opp3(t_war *war)
{
	war->opp[9].arg_len = 1;
	war->opp[9].types[0] = 5;
	war->opp[9].dir_size = 2;
	war->opp[9].cycle = 20;

	war->opp[10].arg_len = 3;
	war->opp[10].types[0] = 105;
	war->opp[10].types[1] = 15;
	war->opp[10].types[2] = 3;
	war->opp[10].dir_size = 2;
	war->opp[10].cycle = 25;

	war->opp[11].arg_len = 3;
	war->opp[11].types[0] = 3;
	war->opp[11].types[1] = 105;
	war->opp[11].types[2] = 15;
	war->opp[11].dir_size = 2;
	war->opp[11].cycle = 25;
	ft_init_opp4(war);

}

void	ft_init_opp2(t_war *war)
{
	war->opp[6].arg_len = 3;
	war->opp[6].types[0] = 105;
	war->opp[6].types[1] = 105;
	war->opp[6].types[2] = 3;
	war->opp[6].dir_size = 4;
	war->opp[6].cycle = 6;

	war->opp[7].arg_len = 3;
	war->opp[7].types[0] = 105;
	war->opp[7].types[1] = 105;
	war->opp[7].types[2] = 3;
	war->opp[7].dir_size = 4;
	war->opp[7].cycle = 6;

	war->opp[8].arg_len = 3;
	war->opp[8].types[0] = 105;
	war->opp[8].types[1] = 105;
	war->opp[8].types[2] = 3;
	war->opp[8].dir_size = 4;
	war->opp[8].cycle = 6;
	ft_init_opp3(war);
}

void	ft_init_opp(t_war *war)
{
	war->opp[1].arg_len = 1;
	war->opp[1].types[0] = 5;
	war->opp[1].dir_size = 4;
	war->opp[1].cycle = 10;

	war->opp[2].arg_len = 2;
	war->opp[2].types[0] = 35;
	war->opp[2].types[1] = 3;
	war->opp[2].dir_size = 4;
	war->opp[2].cycle = 5;

	war->opp[3].arg_len = 2;
	war->opp[3].types[0] = 3;
	war->opp[3].types[1] = 21;
	war->opp[3].dir_size = 4;
	war->opp[3].cycle = 5;

	war->opp[4].arg_len = 3;
	war->opp[4].types[0] = 3;
	war->opp[4].types[1] = 3;
	war->opp[4].types[2] = 3;
	war->opp[4].dir_size = 4;
	war->opp[4].cycle = 10;

	war->opp[5].arg_len = 3;
	war->opp[5].types[0] = 3;
	war->opp[5].types[1] = 3;
	war->opp[5].types[2] = 3;
	war->opp[5].dir_size = 4;
	war->opp[5].cycle = 10;
	ft_init_opp2(war);
}
