/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:47:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/22 19:13:52 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	ft_free_exit(t_war *war, int n_error)
{
	if (n_error > 0)
	{
		ft_putstr("Error #");
		ft_putnbr(n_error);
		write(1, "\n", 1);
	}
	free(war);
	exit(1);
}