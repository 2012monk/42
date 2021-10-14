
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char subject[] = "hello world!";
    char word[] = "";

    printf("%s\n", strstr(subject, word));
    printf("%s\n", ft_strstr(subject, word));

    return 0;
}