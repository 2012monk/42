/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:44:24 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/15 01:44:25 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	f_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_range(int min, int max)
{
	int	*dst;
	int	i;

	if (min >= max)
		return (NULL);
	dst = (int *) malloc(sizeof(int) * f_abs(max - min));
	if (!dst)
		return (NULL);
	i = -1;
	while ((++i + min) < max)
		dst[i] = i + min;
	return (dst);
}

// int main(int argc, char const *argv[])
// {
// 	int *p = ft_range(-__INT_MAX__-1, -2);
// 	printf("%d ㅁㄴㅇㄹㅁㄴㅇㄹ\n", -__INT_MAX__ + 2);
// 	// printf("%s\n", "woking");
// 	if (!p)
// 	{
// 		printf("%s", "NULL RETURED");
// 		return 1;
// 	}
// 	for (int i=0;i<16;i++)
// 		printf("%d ", p[i]);
// 	free(p);
// 	return 0;
// }
