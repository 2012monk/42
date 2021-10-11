
#include <stdio.h>
#include <string.h>
char *ft_strcpy(char *dest, char *src);
int main(void)
{
    char text[] = "Hello 42 SEOUL!!";
	char buffer[100];
	char* ret;

	ret = ft_strcpy(buffer, text);
	printf("%s - %lld\n", buffer, (long long)buffer - (long long)ret);
	ret = strcpy(buffer, text);
	printf("%s - %lld\n", buffer, (long long)buffer - (long long)ret);
    return 0;
}

