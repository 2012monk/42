/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:15:52 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/14 16:20:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	while (*++argv)
	{
		write(1, *argv, ft_strlen(*argv));
		write(1, "\n", 1);
	}
}	
