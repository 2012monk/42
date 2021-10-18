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


int *ft_range(int min, int max)
{
    int *dst;
    int i;

    if (min >= max)
        return (0);
    dst = (int *) malloc(max - min);
    i = min - 1;
    while (++i < max)
        dst[i - min] = i;
    return (dst);
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *p = ft_range(0, 15);

    for (int i=0;i<16;i++)
        printf("%d ", p[i]);
    free(p);
    return 0;
}
