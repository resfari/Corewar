/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:53 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/11/19 15:15:34 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		main(int argc, char **argv)
{
	t_war *war;

	if (!(war = (t_war*)malloc(sizeof(t_war) * 1)))
		return (0);
	ft_init_main(war, argv, argc); // init main struct WAR.
	ft_read_flags_players(war); // func arrange order players w/o flags idk what flags we need to realised
	ft_read_players_code(war); // copy code for each player in player[].struct in War
	ft_decompose_pl_code(war); // decompose comment, name, instructions and check magic key
	ft_fill_arena(war);
	ft_fill_crg(war);
	ft_greatings(war);

	// ft_print_arena(war);

	// ft_init_ncurses();
	ft_play_game(war);
	



	//Tests:
	// ft_test_bytes(war, 1);
	// ft_test_4bytes(war, 1);
	// ft_print_crg_list(war);
	// ft_print_code_for_each_player(war);
	// ft_print_text(war);
	// ft_print_arena(war);
	
	return (0);
}
