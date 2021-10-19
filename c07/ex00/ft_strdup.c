/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:59:33 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/14 17:59:53 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	fstrlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	fstrcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = *src;
}

char	*ft_strdup(char *src)
{
	char			*dst;
	unsigned int	size;

	size = fstrlen(src) + 1;
	dst = (char *) malloc(size);
	if (!dst)
		return (0);
	fstrcpy(dst, src);
	return (dst);
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     char m[] = "hello  ^^7";
//     char *p = ft_strdup(m);

//     printf("%s\n", m);
//     printf("%s\n", p);
//     free(p);
//     return 0;
// }
