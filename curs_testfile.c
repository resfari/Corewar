/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_testfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:11:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/20 20:21:34 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curses.h"

int main(void)
{
	int i;
	initscr();
	// keypad(stdscr, true);
	while (1)
	{
		i = getch();
		if (i == 32)
			printf("32");
		if (i == 27)
			printf("1");
	}
	return (0);
}