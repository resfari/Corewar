/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:19:51 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 20:19:52 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembler.h"

void	error_print()
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int     main(int argc, char **argv)
{
	t_assembler		*ass;

	if (argc != 2 || !ft_check_s1_end_with_s2(argv[1], ".s"))
		error_print();
	ass = (t_assembler*)ft_memalloc(sizeof(t_assembler));
	ass->str = "Lev";
	printf("%s\n", ass->str);
	return (0);
}
