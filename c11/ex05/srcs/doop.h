/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:37:11 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 22:37:13 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

# define DIV_ERR "Stop : division by zero"

# define MOD_ERR "Stop : modulo by zero"

int		ft_atoi(char *str);

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
void	ft_putnbr(int n);
void	f_print(char *str);
#endif // !DOOP_H