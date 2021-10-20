#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int main(int argc, char const *argv[])
{
	char *s[] = {" Hello World! New York  ", "               ", "abcd", "aabbcc", NULL, "abc"};
	char *sep[] = {" ", "     ", "", "abc", NULL, NULL};
	// char **r = ft_split("1233 d dd ", " ");
	char *ss = NULL;
	// printf("\n====\n%s", r[0]);
	// printf("\n====\n%s", r[1]);
	// printf("\n====\n%s", r[2]);
	// if (!ss[0])
	// 	printf("%s", "asdlfkjaslkdfja");
	// free(r);
	int map[256];
	for (int i =0;i<256;i++) map[i] = 0;
	map[0] = 1;
	map[1] = 0;
	map[2] = 0;
	// printf("%d\n", map[0]);
	int i = -1;
	printf("%c\n", s[2][4]);
	while (s[2][++i])
	{
		if (is_seperator(s[2][i], map))
			continue;
		while (s[2][i] && !is_seperator(s[2][i], map))
			printf("%c", s[2][i++]);
		if (!s[2][i])
			break;
		printf("%c\n", s[2][i]);
	}
	char **r;
	for (int i=0;i<6;i++)
	{
		printf("=====================\n");
		r = ft_split(s[i], sep[i]);


		if (r == NULL)
		{
			printf("NULL! %s  %s  ", s[i], sep[i]);
			continue;
		}
		for (int j=0;r[j]!= NULL;j++)
			printf("%d  %d: %s \n", i, j, r[j]);
		free(r);
	}
	return 0;
}