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

int		create_ass(t_asm **ass)
{
	t_asm	*new;
	
	if (!(new = (t_asm*)ft_memalloc(sizeof(t_asm))))
		return (0);
	new->cmd_name_len = ft_strlen(NAME_CMD_STRING);
	new->cmd_comment_len = ft_strlen(COMMENT_CMD_STRING);
	*ass = new;
	return (1);
}

void	reading(t_asm *ass)
{
	if ((ass->fd = open(ass->file_name, O_RDONLY)) == -1)
		error_exit(ass, 1);
	get_name_and_comment(ass);

}

int     main(int argc, char **argv)
{
	t_asm		*ass;

	if (argc != 2 || !ft_check_s1_end_with_s2(argv[1], ".s"))
		error_exit(NULL, 0);
	if (!create_ass(&ass))
		return (0);
	ass->file_name = argv[1];
	reading(ass);
	return (0);
}
