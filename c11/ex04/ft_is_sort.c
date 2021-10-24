/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:06:24 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 22:06:25 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	dsc;

	asc = 1;
	dsc = 1;
	i = -1;
	while (++i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			asc = 0;
			break ;
		}
	}
	i = -1;
	while (++i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			dsc = 0;
			break ;
		}
	}
	return (asc | dsc);
}

// int	less(int a, int b)
// {
// 	return (a - b);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	int a1[] = {1, 1, 3, 4, 5};
// 	int a2[] = {4, 2, 2, 1, 0};
// 	printf("%d %d\n", ft_is_sort(NULL, 5, less), ft_is_sort(a2, 5, less));
// }