#include <stdio.h>

void	ft_putstr(char *str);

int main(){
	
	char tc1[] = "hello world!!";
	char tc2[] = "";
	char tc3[] = "			bye!   end!";

	ft_putstr(tc1);
	ft_putstr(tc2);
	ft_putstr(tc3);
	printf("%s", tc1);
	printf("%s", tc2);
	printf("%s", tc3);
}