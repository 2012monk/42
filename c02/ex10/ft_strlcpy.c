/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:50:25 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 20:04:52 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*start;

	start = dest;
	while (size)
	{
		*dest = *src;
		if (*dest == '\0')
			break;
		dest++;
		src++;
		size--;
	}
}
