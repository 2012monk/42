#include <stdio.h>

void	ft_putnbr(int n);

int main()
{
	ft_putnbr(__INT_MAX__);
	ft_putnbr(-__INT_MAX__-1);
	ft_putnbr(123456789);
	printf("%s", "\n");
	printf("%d", __INT_MAX__);
	printf("%d", -__INT_MAX__-1);
	printf("%d", 123456789);
}