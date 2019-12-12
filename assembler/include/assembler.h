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

# define LBLS_SIZE 500

typedef struct		s_lbl
{
	char			*name;
	int				pos_num;
	struct s_lbl	*same_hash;
}					t_lbl;

typedef struct		s_arg
{
	unsigned char	bytes[4];
	char			*lbl;
	int				size; // to understand how many bites we need
}					t_arg;

typedef struct		s_oper
{
	int				op_num;
	unsigned char	args_type_code;
	int				pos_num;
	int				size;
	struct s_arg	arg[3];
	struct s_oper	*next;
}					t_oper;

typedef struct	s_asm
{
	int			fd;
	char		*line;
	char		*file_name;
	int			y;
	int			x;
	int			cmd_name_len;
	int			cmd_comment_len;
	int			name_len;
	int			comment_len;
	char		*name;
	char		*comment;
	int			current_pos;
	t_oper		*top;
	t_oper		*bot;
	t_lbl		**lbl;
}				t_asm;

char			*ft_str_sub_n(char *s1, int n);
int		ft_atoi_asm(t_asm *ass, const char *str);
void	error_exit(t_asm *ass, int error_num);
char	*get_s_before_spaces(char *s1);
void	get_name_and_comment(t_asm *ass);

void	fill_arg(t_arg *arg, /*unsigned*/ int val, int size);
t_oper	*create_oper(int op_num, int pos_num);
t_oper	*add_oper(t_asm *ass);

int		detect_op(t_asm *ass);

#endif
