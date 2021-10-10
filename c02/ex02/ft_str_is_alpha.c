/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:20:56 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:37:55 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_str(char c)
{
	return ('A' <= c && c <= 'Z') || 
			('a' <= c && c <= 'z');
}

int	ft_str_is_alpha(char *str)
{
	if (!(*str))
		return 1;
	while (*str)
	{
		if (is_str(*str))
			return 1;
		str++;
	}
	return 0;
}	
