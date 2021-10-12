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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (1)
	{
		if (count + 1 < size)
		{
			*dest = *src;
			dest++;
		}
		if (!*src)
			break ;
		src++;
		count++;
	}
	if (count >= size)
		*dest = '\0';
	return (count);
}
