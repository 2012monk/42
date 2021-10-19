/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:25:41 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 21:25:42 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

#include <stdio.h>
int	len_words(char *str, int map[], int flag)
{
	int	i;

	i = 0;
	while (str[i] && map[(unsigned char) str[i]] == flag)
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src, int size)
{
	while (*src && size--)
		*dst++ = *src++;
	*dst = '\0';
}

void	fill_charmap(char *str, int map[])
{
	int	i;

	i = -1;
	while (++i < 256)
		map[i] = 1;
	i = -1;
	while (str[++i])
		map[(unsigned char) str[i]] = 0;
}

int	get_words(char *str, int map[])
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		i += len_words(&str[i], map, 0);
		words++;
		i += len_words(&str[i], map, 1);
	}
	return (i);
}

int	is_seperator(char c, int mask)
{
	
}
char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		j;
	int		map[256];
	int		len;

	if (str == NULL)
		return (NULL);
	fill_charmap(charset, map);
	dest = (char **) malloc(sizeof(char *) * (get_words(str, map) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	printf("%d\n", get_words(str, map));
	while (str[i])
	{
		i += len_words(&str[i], map, 0);
		if (!str[i])
			break ;
		len = len_words(&str[i], map, 1);
		dest[j] = (char *) malloc(sizeof(char) * len);
		if (!dest[j])
			return (NULL);
		ft_strcpy(dest[j++], &str[i], len);
		i += len;
	}
	dest[j] = NULL;
	return (dest);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
	// printf("%s", "dd");
	// char str[] = "h7e8  l 8    l7o wol rd ! ";
	// char c[] = " 78";
	// char **res = ft_split("", "12412");
	char str1[] = "                         ";
	char sep[] = "     ";
	char **r = ft_split(str1, sep);
	for (int i=0;r[i];i++){
		printf("%d %s\n",i, r[i]);
	}
	free(r);
	return 0;
}