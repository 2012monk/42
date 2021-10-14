#include <stdio.h>
#include <unistd.h>
void	ft_putnbr_base(int nb, char *base);
int main(int argc, char const *argv[])
{
	int t1 = -__INT_MAX__ - 1;
	int t2 = __INT_MAX__;
	int t3 = 0;
	int t4 = 1;

	ft_putnbr_base(t2, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(t1, "0123456789abcdef");
	write(1, "\n", 1);
	
	ft_putnbr_base(t2, "01");
	write(1, "\n", 1);
	
	ft_putnbr_base(t1, "01");
	write(1, "\n", 1);
	
	ft_putnbr_base(-1, "013");
	write(1, "\n", 1);
	ft_putnbr_base(100000000, "0123456789ABCDEF");
	write(1, "\n\n", 2);

	printf("%x\n", t1);
	printf("%x\n", t2);
	printf("%s\n", "1111111111111111111111111111111");
	printf("%s\n", "-100000000000000000000000000000000000");
	printf("%d\n", -1);
	printf("%s\n", "5F5E100%");

	// ft_putnbr_base(1234567890, "0123456789");
	// write(1, "\n", 1);
	// ft_putnbr_base(65536, "01");
	// write(1, "\n", 1);
	// write(1, "\n", 1);
	// ft_putnbr_base(2147438647, "0123456");
	// write(1, "\n", 1);
	// ft_putnbr_base(-2147438648, "01234");
	// write(1, "\n", 1);
	// ft_putnbr_base(2147438647, "0123456789ABCDEFGHIJKLMNOPQ");
	return 0;
}