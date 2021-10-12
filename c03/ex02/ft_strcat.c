/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:24:17 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/12 18:24:18 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (start);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char t1[40];
	char t2[] = "recieved";
	strcpy(t1,"message ");
	ft_strcat(t1, t2);
	printf("%s", t1);
	return 0;
}