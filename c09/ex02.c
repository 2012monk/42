#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int main()
{
	char *s[] = {" Hello World! New York  ", "               ", "abcd", "aabbcc", NULL, "abc"};
	char *sep[] = {" ", "     ", "", "abc", NULL, NULL};
	// char **r = ft_split("1233 d dd ", " ");
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
	// printf("%c\n", s[2][4]);
	// while (s[2][++i])
	// {
	// 	if (is_seperator(s[2][i], map))
	// 		continue;
	// 	while (s[2][i] && !is_seperator(s[2][i], map))
	// 		printf("%c", s[2][i++]);
	// 	if (!s[2][i])
	// 		break;
	// 	printf("%c\n", s[2][i]);
	// }
	// char **ss = ft_split(NULL, NULL);
	// printf("%s\n", ss[0]);
	// free(ss);
	char **r;
	// r = ft_split(NULL, NULL);
	for (int i=0;i<6;i++)
	{
		printf("%d=====================\n", i);
		r = ft_split(s[i], sep[i]);

		if (r == NULL)
		{
			printf("NULL! %s  %s \n ", s[i], sep[i]);
			continue;
		}
		for (int j=0;r[j]!= NULL;j++)
		{
			printf("%d  %d: %s \n", i, j, r[j]);
			// free(r[j]);
		}
		if (r == NULL){
			printf("%s", "catch");
		}
		// printf("free %d\n", i);

		free(r);
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:35:48 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/21 10:35:52 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

// void	ft_strncpy(char *dst, char *src, int len)
// {
// 	while (*src && len--)
// 		*dst++ = *src++;
// 	*dst = '\0';
// }

// void	fill_charmap(char *str, int map[])
// {
// 	int	i;

// 	i = 0;
// 	map[0] = 1;
// 	while (++i < 256)
// 		map[i] = 0;
// 	i = -1;
// 	if (!str)
// 		return ;
// 	while (str[++i])
// 		map[(unsigned char) str[i]] = 1;
// }

// int	is_seperator(char c, char *charset)
// {
// 	int	i;

// 	if (!charset)
// 		return (0);
// 	i = -1;
// 	while (charset[++i])
// 	{
// 		if (charset[i] == c)
// 			return (1);
// 	}
// 	return (0);
// }

// int	count_words(char *str, char *charset) 
// {
// 	int	i;
// 	int	words;

// 	i = 0;
// 	words = 0;
// 	while (str[i])
// 	{
// 		if (is_seperator(str[i], charset))
// 		{
// 			i++;
// 			continue ;
// 		}
// 		words++;
// 		while (str[i] && !is_seperator(str[i], charset))
// 			i++;
		
// 	}
// 	return (words);
// }

// char	**split_words(char *str, char *charset, char **dst)
// {
// 	int	i;
// 	int	j;
// 	int	size;

// 	i = 0;
// 	j = 0;
	
// 	while (str[j])
// 	{
// 		while (is_seperator(str[j], charset))
// 			j++;
// 		size = 0;
// 		if (!str[j])
// 			break ;
// 		while (str[j + size] && !is_seperator(str[j + size], charset))
// 			size++;
// 		dst[i] = (char *) malloc(sizeof(char) * (size + 1));
// 		if (!dst[i])
// 			return (NULL);
// 		ft_strncpy(dst[i], &str[j], size);
// 		j += size;
// 		i++;
// 		if (!str[j])
// 			break ;
// 	}
// 	return (dst);
// }

// char	**ft_split(char *str, char *charset)
// {
// 	char	**dst;

// 	if (str == NULL)
// 		return (NULL);
// 	dst = (char **) malloc(sizeof(char *) * (count_words(str, charset) + 1));
// 	if (!dst)
// 		return (NULL);
// 	dst[count_words(str, charset)] = 0;
// 	// printf("words %s  %d\n",str, count_words(str, charset));
// 	return (split_words(str, charset, dst));
// }