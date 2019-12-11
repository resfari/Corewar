/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:22:44 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 22:22:45 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembler.h"

char	*ft_str_sub_n(char *s1, int n)
{
	char	*s2;
	int		i;

	if (!s1 || ft_strlen(s1) < n)
		return (NULL);
	s2 = ft_strnew(n);
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}
