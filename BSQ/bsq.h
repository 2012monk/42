/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:47:06 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 16:47:07 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_board
{
	char	**board;
	int		height;
	int		width;
	char	obstacle;
	char	empty;
	char	fill;
}	t_board;

int		ft_atoi(char *str);
char	**get_lines(char *file);
char	**ft_split(char *str, char c);
int		count_arr(char **strs);
int		ft_strlen(char *str);
t_board	*parse_map(char *file);
int		max(int a, int b);
void	print_board(t_board *map);
void	throw_err(void);
void	solve(t_board *map);
t_board	*parse_map(char *file);
int		min(int a, int b, int c);
#endif // !BSQ_H
