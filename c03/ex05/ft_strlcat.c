/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:18:31 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 15:18:32 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int	size;

	size = 0;
	while (*src++)
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_size;
	unsigned int	src_size;

	dst_size = ft_strlen(dest);
	src_size = 0;
	dest += dst_size;
	while (*src && dst_size + src_size + 1 < size)
	{
		*dest++ = *src++;
		src_size++;
	}
	while (*src++)
		src_size++;
	*dest = '\0';
	if (size <= dst_size)
		return (src_size + size);
	return (src_size + dst_size);
}
