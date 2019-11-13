
#include <stdio.h>

# define mod_1(x) x > 4095 ? x % 4096 : x

int main(void)
{
	int x = 4096;
	int x1 = 20;
	printf("x1 = %d, x2 = %d", mod_1(x), mod_1(x1));
	return (0);
}