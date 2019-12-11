/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:31:37 by pnita             #+#    #+#             */
/*   Updated: 2019/12/11 22:31:38 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembler.h"

char	*s1_before_spaces_in_input_s2(char *s1)
{
	int		i;
	int		len;
	char	*s2;

	if (!s1 || !*s1)
		return (NULL);
	len = 0;
	while (s1[len] && s1[len] != ' ' && s1[len] != '\t')
		++len;
	s2 = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}

void	get_name(t_asm *ass, char *line)
{
	// printf("IN GET_NAME\n");
	ass->x += ass->cmd_name_len;
	while (line[ass->x])
	{
		if (line[ass->x] != ' ' && line[ass->x] != '\t')
		{
			if (line[ass->x] == '\"' && !ass->name)
			{
				++ass->x;
				if ((ass->name_len = ft_len_before_delim(line + ass->x, '\"')) == -1)
					error_exit(ass, 5);
				ass->name = ft_str_sub_n(line + ass->x, ass->name_len);
				ass->x += ass->name_len;
			}
			else
			{
				ass->err_token = s1_before_spaces_in_input_s2(line + ass->x);
				error_exit(ass, 4);
			}
		}
		++ass->x;
	}
	// printf("x = %i\n", ass->x);
}

void	get_comment(t_asm *ass, char *line)
{
	// printf("IN GET_COMMENT\n");
	ass->x += ass->cmd_comment_len;
	while (line[ass->x])
	{
		if (line[ass->x] != ' ' && line[ass->x] != '\t')
		{
			if (line[ass->x] == '\"' && !ass->comment)
			{
				++ass->x;
				if ((ass->comment_len = ft_len_before_delim(line + ass->x, '\"')) == -1)
					error_exit(ass, 5);
				ass->comment = ft_str_sub_n(line + ass->x, ass->comment_len);
				ass->x += ass->comment_len;
			}
			else
			{
				ass->err_token = s1_before_spaces_in_input_s2(line + ass->x);
				error_exit(ass, 4);
			}
		}
		++ass->x;
	}
	// printf("x = %i\n", ass->x);
}

void	get_name_and_comment(t_asm *ass)
{
	char	*line;

	while ((!ass->name || !ass->comment) && get_next_line(ass->fd, &line) > 0)
	{
		if (line)
		{
			while (line[ass->x])
			{
				if (line[ass->x] != ' ' && line[ass->x] != '\t')
				{
					if (!ft_strncmp(line + ass->x, NAME_CMD_STRING, ass->cmd_name_len))
						get_name(ass, line);
					else if (!ft_strncmp(line + ass->x, COMMENT_CMD_STRING, ass->cmd_comment_len))
						get_comment(ass, line);
					else
					{
						ass->err_token = s1_before_spaces_in_input_s2(line + ass->x);
						error_exit(ass, 4);
					}
				}
				else
					++ass->x;
			}
		}
		++ass->y;
		ass->x = 0;
		ft_strdel(&line);
	}
	if (!ass->comment || !ass->name)
		error_exit(ass, 3);
	// printf("name = %s	comment = %s\n", ass->name, ass->comment);
}
