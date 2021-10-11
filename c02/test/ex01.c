#include <stdio.h>
#include <string.h>
char *ft_strncpy(char *dest, char *src, unsigned int size);
int main(int argc, char const *argv[])
{
    char dest[100];
    char src[100] = "1234512345";
    char *ret;
    // int len = argv[2] - '0';
    // strcpy(src, argv[1]);
    
    ret = strncpy(dest, src, 100);
    printf("%s  addr : %ld\n",dest , (long) ret - (long) dest);
    ret = ft_strncpy(dest, src, 100);
    printf("%s  addr : %ld\n",dest , (long) ret - (long) dest);
    // memset(dest, 30, 100);
    for (int i=10;i<100;i++)
        if (dest[i] != 0)
            printf("failed %c", dest[i]);
            
    return 0;
}
