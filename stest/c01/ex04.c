#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 5;

	int s = 2;
	int m = 0;

	ft_ultimate_div_mod(&a, &b);

	printf("%d %d\n",a,b);
	printf("%d %d\n",s,m);
	return 0;
}
