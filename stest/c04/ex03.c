#include <stdio.h>
int	ft_atoi(char *str);
int main()
{
	printf("%d %d\n", ft_atoi("----123ccc"), 123);
	printf("%d %d\n", ft_atoi("-----143kkk"), -143);
	printf("%d %d\n", ft_atoi("\n\n\n   --++--45d670kk"), 45);
	printf("%d %d\n", ft_atoi("\n\n\n   --++--d670kk"), 0);
}