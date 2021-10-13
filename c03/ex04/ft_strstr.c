/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:52 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 14:59:53 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	while (*s2 && *s2 == *s1)
	{
		result += *s1++ - *s2++;
	}
	if (*s1)
		result += *s1;
	if (*s2)
		result -= *s2;
	return (result);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*to_find)
		return (str);
	while (str[i] && to_find[j])
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = str[i] == to_find[0];
		i++;
	}
	if (!to_find[j])
		return (str + i - j);
	return (0);
}
