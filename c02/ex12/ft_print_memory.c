/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:11:09 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 21:42:46 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_hex(int n)
{
	int	i;
	int	cur;

	i = 16;
	while (i < n)
		i *= 16;
	while (i != 0)
	{
		cur = n / i;
		n %= i;	
		if (i > 10)
			put_char(cur + 'A' - 1);
		else
			put_char(cur + '0');
	}
}

void	print_char(char *str)
{
	int	i;

	i = 0;
	while (i < 16 && *str)
	{
		if (*str == 127 || *str < 33)
			ft_put_char('.');
		else
			ft_put_char(*str);
	}
}
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	int		j;
	char	*str;
	
	i = 0;
	str = (char *) addr;
	while (i < size)
	{
		print_hex(&str[i]);
		ft_put_char(':');
		ft_put_char(' ');
		j = 0;
		while (j < 16 && *str)
		{
			print_hex(*str);
			if (j % 2 == 0)
				ft_put_char(' ');
			j++;
			str++;
		}
		ft_put_char(' ');
		print_char(&str[i]);
		ft_put_char('\n');
		i += 16;
	}
}

int main(void)
{
	char msg[] = "Hello Wolrd!\n\n\ni just cant't help it -=~~\t\t\t\tls";
	ft_print_memory(msg, 50);
	return 0;
}
