#include <stdio.h>
int ft_putstr_non_printable(char *c);
int main(int argc, char const *argv[])
{
	// printf("%x\n", -112);
	char msg[] = "a\x7f\b\n\t\r;\x8el";
	ft_putstr_non_printable(msg);
	printf("%x", (0x7f & 0x8e));
	return 0;
}