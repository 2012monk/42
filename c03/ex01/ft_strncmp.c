/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:56:57 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/12 17:56:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int size)
{
	int	result;

	result = 0;
	while (*s2 && *s2 == *s1 && size--)
		result += *s1++ - *s2++;
	if (*s1 && size)
		result += *s1;
	if (*s2 && size)
		result -= *s2;
	return (result);
}
