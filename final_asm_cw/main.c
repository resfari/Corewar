/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:58:34 by ctestabu          #+#    #+#             */
/*   Updated: 2019/12/10 20:49:42 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf/include/ft_printf.h"
#include <fcntl.h>
#include "includes/op.h"
#include "includes/cw.h"

int check_valid_name(char *name)
{
	size_t i;

	i = ft_strlen(name);
	if (i > 2 && name[i] == '\0' && name[i - 2] == '.' && name[i - 1] == 's')
		return (1);
	return (0);
}

char  print_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 2);
	exit(0);
}

int		parsing_line_check(char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ALT_COMMENT_CHAR || line[i] == COMMENT_CHAR)
			return (1);
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int  read_file_s(char *filename)
{
	int fd;
	char *line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_putendl_fd("FILE_NOT_FOUND", 2);

	while (get_next_line(fd, &line) > 0 )
	{
		if (!parsing_line_check(line))
			print_error("Missing .name or .comment at file ");

	}
	return (0);
}


void		assemle(char *filename)
{
	t_asc	*asc;
	//for token too

	if (!(asc =(t_asc*)ft_memalloc(sizeof(t_asc))))
		print_error("NO memory for struct");
	
}

int main(int ac, char **av)
{	
	int helper;
	if (ac != 2)
	{	
		ft_putendl("\"Usage: ./asm champion_name.s\"");
		print_error("Too many or few arguments");	 
	}
	if (ac == 2 && check_valid_name(av[1]))
	{	
		read_file_s(av[1]);
		// write(2, "\n", 2);
	}
	else if (!check_valid_name(av[1]))
		print_error("Invalid file name, yebok");
	return (0);

}
