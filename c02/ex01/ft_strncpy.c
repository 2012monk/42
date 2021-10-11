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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*start;

	start = dest;
	while (n)
	{
		*dest = *src;
		if (*dest == 0)
			break ;
		dest++;
		src++;
		n--;
	}
	if (n)
	{
		while (--n)
			*++dest = '\0';
	}
	return (start);
}
