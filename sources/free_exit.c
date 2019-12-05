/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:47:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/05 20:11:43 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_print_usage(void)
{
	ft_putstr("################################################################################\n");
	ft_putstr("Usage: ./corewar [-dump N | -v | -live] [-a] [-n N] <champion1.cor> <...>\n");
	ft_putstr("    -dump N      : Dumps memory after N cycles then exits\n");
	ft_putstr("    -live        : Show lives\n");
	ft_putstr("    -v           : Ncurses output mode\n");
	ft_putstr("    -a        	 : Prints output from \"aff\" (Default is to hide it)\n");
	ft_putstr("    -n N         : Set <N> of the next player\n");
	ft_putstr("################################################################################\n");
}

void	ft_free_exit(t_war *war, int n_error)
{
	if (n_error == 11)
	{
		ft_print_usage();
	}
	else if (n_error > 0)
	{
		ft_putstr("Error #");
		ft_putnbr(n_error);
		write(1, "\n", 1);
	}
	free(war);
	exit(1);
}