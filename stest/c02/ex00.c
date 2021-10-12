#include <stdio.h>
#include <string.h>
char *ft_strcpy(char *dest, char *src);

int main(int argc, char const *argv[])
{
	char dest[100];
    char src[100];

    strcpy(src, argv[1]);

	char *ret = ft_strcpy(dest, src);
	printf("%s - %ld\n", dest, (long) ret - (long) dest);
	// printf("%s", "==========\n");
    ret = strcpy(dest, src);
	printf("%s - %ld\n", dest, (long) ret - (long) dest);
	return 0;
}