/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:05:58 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:20:08 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < sizeof(dest))
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

int main(void){
	char dest[10];
	char src[10] = "HELLO!!";
	ft_strncpy(dest, src, 3);
	printf("%s", dest);
	return 0;
}
