/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:22 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/14 16:24:23 by seounlee         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	sort_in_lex(argv + 1, 0, argc - 2);
	while (*++argv)
	{
		write(1, *argv, ft_strlen(*argv));
		write(1, "\n", 1);
	}
	return (0);
}
