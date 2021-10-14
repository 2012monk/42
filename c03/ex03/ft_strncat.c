/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:57:02 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/12 20:02:22 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned long	dst_size;
	char			*start;

	dst_size = sizeof(dest);
	start = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}
