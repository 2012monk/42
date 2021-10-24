/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:13:53 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 23:13:54 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *s1, char *s2)
{
	while (*s2 && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	partition(char **arr, int lo, int hi)
{
	char	*pivot;
	int		i;
	char	*tmp;

	i = lo;
	pivot = arr[hi];
	while (i <= hi)
	{
		if (compare(arr[i], pivot) < 0)
		{
			tmp = arr[i];
			arr[i] = arr[lo];
			arr[lo++] = tmp;
		}
		i++;
	}
	tmp = arr[hi];
	arr[hi] = arr[lo];
	arr[lo] = tmp;
	return (lo);
}

void	sort_in_lex(char **arr, int lo, int hi)
{
	int	pivot;

	if (lo >= hi)
		return ;
	pivot = partition(arr, lo, hi);
	sort_in_lex(arr, lo, pivot - 1);
	sort_in_lex(arr, pivot + 1, hi);
}

void	ft_sort_string_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	sort_in_lex(tab, 0, len - 1);
}
