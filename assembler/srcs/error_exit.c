/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:29:13 by pnita             #+#    #+#             */
/*   Updated: 2019/12/11 22:29:14 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembler.h"

void	delete_all(t_asm *ass)
{
	if (ass->err_token)
		ft_strdel(&ass->err_token);
	free(ass);
	ass = NULL;
}

void	error_exit(t_asm *ass, int error_num)
{
	if (!error_num)
		ft_printf("ERROR. Can be only one file and it's name must end with \".s\"\n");
	else if (error_num == 1)
	{
		ft_printf("ERROR. Can't open %s\n", ass->file_name);
	}
	else if (error_num == 2)
	{
		ft_printf("ERROR. Can't read %s\n", ass->file_name);
	}
	else if (error_num == 3)
	{
		ft_printf("ERROR. Unexpected token \"(null)\" at [%.3i:%.3i]\n", ass->y + 1, ass->x + 1); // not always give right koords
	}
	else if (error_num == 4)
	{
		ft_printf("ERROR. Unexpected token \"%s\" at [%.3i:%.3i]\n", ass->err_token, ass->y + 1, ass->x + 1);
	}
	else if (error_num == 5)
	{
		ft_printf("ERROR. Lexical error\n");
	}
	else
		ft_printf("ERROR\n");
	if (ass)
		delete_all(ass);
	exit(1);
}
