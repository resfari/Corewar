/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:49:02 by ctestabu          #+#    #+#             */
/*   Updated: 2019/12/10 18:52:16 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H
// # include "../libft/includes/libft.h"
# include "op.h"

typedef struct 	s_ascontrol
{
	char	name[PROG_NAME_LENGTH + 1]; // .name of .s file
	char	comment[COMMENT_LENGTH + 1]; // .comment
	int		fd; //fd when file opened to read
	int 	row; // row for errors managment
	int		col; // same for column

}				t_asc;

# define FD 	asc->fd
# define ROW	asc->row
# define COL	asc->col

typedef enum		e_type
{
	Register = 1,
	Direct,
	Operation,
	Indirect,
	Separator,
	Label,
	Dir_label,
	Ind_label,
	Line_feed,
	End
}					t_type;

typedef struct		s_token // struct for tokens exept labels
{
	char 			*name;
	t_type			type;
}					t_token;


typedef struct		s_label
{
	char			*name;
	int				bytes;
	struct s_label	*next;
}					t_label;



#endif

