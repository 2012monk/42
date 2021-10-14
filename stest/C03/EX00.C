#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char orig[] = "123123";
	char comp[] = "2222";
	// printf("%d\n", strncmp(orig, comp, 3));
	// printf("%d\n", ft_strncmp(orig, comp, 3));
	printf("%d\n", strcmp(orig, comp));
	printf("%d\n", ft_strcmp(orig, comp));
	return 0;
}