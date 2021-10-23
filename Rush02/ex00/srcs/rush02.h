/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:02:40 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 10:02:41 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

typedef struct s_map
{
	char	*key;
	char	*value;
}	t_map;

typedef struct s_num_map
{
	char	*value;
	char	*key;
	int		num;
}	t_num_map;

extern t_map		**g_number_map;

extern t_num_map	**g_digit_map;

extern char			**g_unique_map;

// error == -1
int		init(char *dict);

int		fill_map(void);

char	*read_file(int fd);

char	**split_by_sep(char *str, char sep);

t_map	**get_dict(char *file);

char	*find_digit(int n);

char	*find_unique(int n);

int		validate_input(char *str);
#endif // !RUSH02_H
