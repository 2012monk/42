#include "bsq.h"
#define BUF_SIZE 4096 
void	f_memcpy(void *dst, void *src, unsigned int len)
{
	char			*to;
	char			*from;
	unsigned int	i;

	to = (char *) dst;
	from = (char *) src;
	i = 0;
	printf("%c++++++++\n", from[0]);
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
}

void	*ft_realloc(void *src, unsigned int old_size, unsigned int new_size)
{
	void	*pt;

	if (!src)
		return (malloc(sizeof(char) * new_size));
	if (old_size < new_size)
	{
		pt = malloc(sizeof(char) * new_size);
		if (pt == NULL)
		{
			printf("%s", "malloc failed\n");
			return NULL;
		}
		((char *) pt)[new_size] = 0;
		f_memcpy(pt, src, old_size);
		free(src);
		return (pt);
	}
	return (src);
}
char	*parse_file(int fd, int *total)
{
	char	*buf;
	int		size;
	int		cur;
	int		i;

	size = 1;
	buf = (char *) malloc(sizeof(char) * (BUF_SIZE));
	if (!buf)
	{
		printf("%s", "error");
		return NULL;
	}
	cur = BUF_SIZE;
	i = 0;
	while (size > 0)
	{
		if (errno)
		{
			printf("%s \n", strerror(errno));
			return (NULL);
		}
		size = read(fd, &buf[i], BUF_SIZE);
			printf("%c========================\n", buf[0]);
		*total = *total + size;
		if (size == BUF_SIZE)
		{
			printf("%d\n", *total);
			buf = ft_realloc(buf, *total, sizeof(char) * (*total + BUF_SIZE));
		}
		i += size;
	}
	buf[*total] = '\0';
	return (buf);
}
int main(void)
{
	char *words;
	int	size;
	// int	i;
	size = 0;

	words = parse_file(0, &size);
	// words = malloc(sizeof(char) * 120000);
	// words = malloc(sizeof(char *) * 7);
	// words[0] = "1";
	// words[1] = "2";
	// words[2] = "3";
	// words[3] = "4";
	// words[4] = "5";
	// words[5] = "6";

	// read(0, words, 120000);
printf("%c-------\n", words[0]);
	// char **n = malloc(sizeof(char *) * 7);
	// f_memcpy(n, words, sizeof(char *) * 7);
	// printf("\n====%d=====\n", size);
	// for (int i =0;i<7;i++){
	// 	printf("%s\n", n[i]);
	// }
	// printf("%d\n", size);
	// printf("%d\n", size);
	// write(1, words, size);
	// write(1, words, 1);
	// write(1, words, 2);
	// printf("%d\n", size);
	// i = -1;
	// while (++i < size && words[i])
	// {
	// 	write(1, &words[i], 1);
	// }
	
}