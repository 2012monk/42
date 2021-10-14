#include <stdio.h>
#include <string.h>
int	ft_strlen(char *str);
int main()
{
	char tc1[] = "12345";
	char tc2[] = "";
	char tc3[] = "!!  !!  !!";

	printf("origin: %lu compare: %d\n", strlen(tc1), ft_strlen(tc1));
	printf("origin: %lu compare: %d\n", strlen(tc2), ft_strlen(tc2));
	printf("origin: %lu compare: %d\n", strlen(tc3), ft_strlen(tc3));
}