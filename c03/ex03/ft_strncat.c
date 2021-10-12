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
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	
	while (*src && nb--)
		*dest++ = *src++;
	if (*dest)
		*dest = '\0';
	return (start);
}

int	main()
{
	char dest[40] = "helloWorld!";

}
