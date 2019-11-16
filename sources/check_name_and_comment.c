#include "../include/corewar.h"

int		ft_check_chars(int is_valid)
{
	if ((is_valid >= 65 && is_valid <= 90) ||
	(is_valid >= 97 && is_valid <= 122) ||
	(is_valid >= 42 && is_valid <= 57) ||
	is_valid == 32 || is_valid == 39 || is_valid == 61 || is_valid == 33 || is_valid == 0)
	{
		return (1);
	}
	printf("ERROR");
	return (0);
}

void	ft_check_name(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 4;
	while (i < PROG_NAME_LENGTH)
	{
		if (ft_check_chars(war->player[num].text[j]) == 0)
		{
			ft_free_exit(war, 8);
		}
		war->player[num].name[i] = war->player[num].text[j];
		i++;
		j++;
	}
}

void	ft_check_comment(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 12 + PROG_NAME_LENGTH;
	while (i < COMMENT_LENGTH)
	{
		if (ft_check_chars(war->player[num].text[j]) == 0)
		{
			ft_free_exit(war, 8);
		}
		war->player[num].comment[i] = war->player[num].text[j];
		i++;
		j++;
	}
}
