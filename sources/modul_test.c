
#include <stdio.h>

# define mod_1(x) (x < 0 ? x % 4096 + 4096: x % 4096)

int main(void)
{
	int x = -409764789;
	printf("x1 = %d", mod_1(x));
	return (0);
}