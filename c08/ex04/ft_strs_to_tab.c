/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:25:28 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 01:25:30 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

int	f_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	fstrcpy(char *dst, char *src)
{
	int	len;

	len = f_strlen(src);
	while (len--)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(char *src)
{
	char			*dst;
	unsigned int	size;

	size = f_strlen(src) + 1;
	dst = (char *) malloc(sizeof(char) * size);
	if (dst == NULL)
		return (NULL);
	fstrcpy(dst, src);
	return (dst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	if (ac <= 0)
		return (NULL);
	arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = f_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

// #include <stdio.h>
// int main()
// {
// 	char *av1[] = { "HelloWorld!" };

// 	t_stock_str *a = ft_strs_to_tab(1, av1);
// 	// printf("%s\n", a->str);
// 	// printf("%s\n", a->copy);
// 	// printf("%d\n", a->size);

// 	char *av2[] = {"aa", "bb", "cc", "ddef"};
// 	t_stock_str *b = ft_strs_to_tab(4, av2);
// 	for (int i=0;i < 10;i++)
// 	{
// 		if ((b+i)->str == 0)
// 			break ;
// 		printf("%s %p %p\n", (b+i)->str, av2[i], (b+i)->str);
// 		printf("%s %p %p\n", (b+i)->copy, av2[i], (b+i)->copy);
// 		printf("%d\n", (b+i)->size);
// 	}
// 	free(a);
// 	free(b);
// 	return 0;
// }
