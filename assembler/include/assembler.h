/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:22:11 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 20:23:10 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../../ft_printf/include/ft_printf.h"
# include "op.h"
# include "operations.h"

typedef struct	s_asm
{
	int			fd;
	char		*file_name;
	int			y;
	int			x;
	int			cmd_name_len;
	int			cmd_comment_len;
	int			name_len;
	int			comment_len;
	char		*name;
	char		*comment;
	char		*err_token;
}				t_asm;

char			*ft_str_sub_n(char *s1, int n);
void	error_exit(t_asm *ass, int error_num);
char	*s1_before_spaces_in_input_s2(char *s1);
void	get_name_and_comment(t_asm *ass);

#endif
