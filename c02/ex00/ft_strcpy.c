/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:51:34 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:18:25 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;
	return dest;
}

int	main(void)
{
	char src[10];
	char msg[10] = "hello";
	ft_strcpy(src, msg);
	printf("%s", src);
	return 0;
}
