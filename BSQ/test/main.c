#include <stdio.h>
#include <unistd.h>

int main(){
    char buf[100];

    int i = 0;
    while (read(0, &buf[i], 1) > 0 && i < 100)
        i++;
    i = 0;
    while (buf[i] && i < 100)
        printf("%c", buf[i++]);
}