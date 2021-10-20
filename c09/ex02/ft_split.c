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

void	ft_strncpy(char *dst, char *src, int len)
{
	while (*src && len--)
		*dst++ = *src++;
	*dst = '\0';
}

void	fill_charmap(char *str, int map[])
{
	int	i;

	i = 0;
	map[0] = 1;
	while (++i < 256)
		map[i] = 0;
	i = -1;
	if (!str)
		return ;
	while (str[++i])
		map[(unsigned char) str[i]] = 1;
}


int	is_seperator(char c, int map[])
{
	return (map[(unsigned char) c]);
}

int	count_words(char *str, int map[])
{
	int	i;
	int	words;

	i = -1;
	words = 0;
	while (str[++i])
	{
		if (is_seperator(str[i], map))
			continue ;
		words++;
		while (str[i] && !is_seperator(str[i], map))
			i++;
	}
	return (words);
}


char	**ft_split(char *str, char *charset)
{
	int		map[256];
	char	**dst;
	int		i;
	int		j;
	int		size;

	printf("%d",1);
	// return ((char **) malloc(0));
	if (str == NULL)
		return (NULL);
	fill_charmap(charset, map);
	dst = (char **) malloc(sizeof(char *) * (count_words(str, map) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = -1;

	printf("%d---\n", count_words(str, map));
	dst[count_words(str, map)] = 0;
	while (i < size && str[++j])
	{
		// printf("%d %c\n", is_seperator(str[i], map), str[i]);
		dst[i] = NULL;
		if (is_seperator(str[j], map))
			continue ;
		size = 0;
		// printf("%c %d\n", str[j], map[str[j]]);
		while (str[j + size] && !is_seperator(str[j + size], map))
			size++;
		// printf("%d========word size\n", size);
		dst[i] = (char *) malloc(sizeof(char) * (size + 1));
		if (!dst[i])
			return (NULL);
		ft_strncpy(dst[i++], &str[j], size);
		j += size;
		if (!str[j])
			break ;
	}
	dst[i] = NULL;
	return (dst);
}

