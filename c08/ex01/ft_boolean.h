/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:06:39 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 01:06:42 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG	"I have an even number of arguments.\n"

# define ODD_MSG	"I have and odd number of arguments.\n"

# define EVEN(N)	N % 2 == 0

# define TRUE		1

# define FALSE		0

# define SUCCESS	0

typedef int	t_bool;

#endif
