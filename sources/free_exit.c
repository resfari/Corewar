/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:47:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/03 18:54:07 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/corewar.h"

void	ft_free_exit(t_war *war, int n_error)
{
	ft_putstr("Error #");
	ft_putnbr(n_error);
	write(1, "\n", 1);
	free(war);
	exit(1);
}