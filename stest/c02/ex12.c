#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void	*ft_print_memory(void *addr, unsigned int size);

void nonPrint(char *buf){
    for (int i=0;i<16;i++,buf++){
        if (*buf < 32 || *buf == 127)
            printf("%c", '.');
        else
            printf("%c", *buf);
        
    }
}

int main(void)
{
	int fd = open("./t", O_RDONLY);
	char buffer[200];
	read(fd, buffer, 100);
    int i;
 
    for (i = 0;i < 100;i += 16){
        printf("%016lx: ", (unsigned long) &buffer[i]);
        for(int j=0;j<16 && buffer[j+i];j++){
            printf("%02x", buffer[j + i]);
            if (j&1) printf("%c", ' ');
        }
        printf("%c", ' ');
        nonPrint(&buffer[i]);
        printf("%c", '\n');
        // printf(" %.*s\n", 16, &buffer[i]);
    }

	ft_print_memory(buffer, 100);
	close(fd);
	return 0;
}