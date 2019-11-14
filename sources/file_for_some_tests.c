#include "../include/corewar.h"

// void	ft_test_reverse(t_war *war, int num)
// {
// 	unsigned int res_uns;
// 	unsigned char *ptr;

// 	ptr = (unsigned char*)&(war->player[num].code);
	

// }

void	ft_test_4bytes(t_war *war, int num)
{
	unsigned short res_short;
	int res_int;
	int i;
	char *ptr;
	res_short = 2342;
	// ptr = (char*)&(res_int);
	(void)war;
	// printf("short = %lu, unsig = %lu\n", sizeof(res_short), sizeof(res_int));
	ptr = (char*)&(war->arena[1].code);
	// ptr = (char*)&(war->field[1]);
	int byte = 0;
	(void)num;
	while (byte < 1)
	{
		i = 7;
		while (i >= 0)
		{
			if (ptr[byte] & 1 << i)
				printf("1");
			else
			{
				printf("0");
			}
			i--;
		}
		byte++;
	}
	printf("\n");

	// ptr = (char*)&(war->player[num].code[1]);
	// int byte = 0;
	// while (byte < 4)
	// {
	// 	i = 7;
	// 	while (i >= 0)
	// 	{
	// 		if (ptr[byte] & 1 << i)
	// 			printf("1");
	// 		else
	// 		{
	// 			printf("0");
	// 		}
	// 		i--;
	// 	}
	// 	byte++;
	// }
	// printf("\n");


	// i = 0;
	// res_short = ((255 & war->player[num].code[3]) | (255 & war->player[num].code[2]) << 8 |
	// (255 & war->player[num].code[1]) << 16 | (255 & war->player[num].code[0]) << 24);
	res_int = ((255 & ptr[0]) << 24 | (255 & ptr[1]) << 16 |
	(255 & ptr[2]) << 8 | (255 & ptr[3]));
	printf("\n%d\n", res_int);
	// printf("\nshort = %hu, unsigned = %u", res_short, res_int);
}

void	ft_test_bytes(t_war *war, int num)
{
	char *str;
	unsigned char *ptr;
	int d;
	int res[3];
	int byte;
	int correct;
	int i;
	
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	d = 0;
	str = war->player[num].code;
	ptr = (unsigned char*)&(str[1]);
	byte = 7;
	i = 0;
	while (byte > 1)
	{
		correct = 1;
		if (ptr[d] & 1 << byte)
		{
			res[i] = 5;
			correct = 0;
		}
		byte--;
		if (ptr[d] & 1 << byte)
		{
			res[i] += 2 + correct;
		}
		i++;
		byte--;
	}
	printf("\nres1 = %d, res2 = %d, res3 = %d\n", res[0], res[1], res[2]);
}

void	ft_print_text(t_war *war)
{
	int i;

	i = 1;
	printf("Max Code Size = %d", MAX_CODE_SIZE);
	while (i <= war->numb_players)
	{
		printf("%s\n", war->player[i].path);
		printf("player: %d\n len = %d\n", i, war->player[i].text_len);
		i++;
	}
}

void	ft_print_arena(t_war *war)
{
	int a;

	a = 0;
	while (a < MEM_SIZE)
	{
		if (a % 64 == 0)
			write(1, "\n", 1);
		// ft_putnbr(war->arena[a].code);	
		ft_putnbr(war->field[a]);
		write(1, " ", 1);
		a++;
	}
	write(1, "\n", 1);
}

void	ft_print_code_for_each_player(t_war *war)
{
	int i;
	int j;
	int c;

	i = 1;
	while (i <= war->numb_players)
	{
		j = 0;
		while (j < war->player[i].code_len)
		{
			c = (int)(war->player[i].code[j] & 255);
			ft_putnbr(c);
			write(1, "  ", 3);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ft_print_crg_list(t_war *war)
{
	t_crg  *help;

	help = war->top;
	while (help)
	{
		printf("player = %d, position = %d ", help->player, help->pos);
		printf("die = %d live = %d\n", help->die, help->live);
		help = help->next;
	}
	// printf("Check Top  player = %d pos = %d\n", war->top->player, war->top->pos);
	// printf("Check Bot  player = %d pos = %d\n", war->bot->player, war->bot->pos);
}
