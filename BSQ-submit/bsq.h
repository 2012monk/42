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

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 1048576

typedef struct s_board
{
	char	**board;
	int		height;
	int		width;
	char	obstacle;
	char	empty;
	char	fill;
}	t_board;

int		max(int a, int b);
void	print_board(t_board *map);
void	throw_err(void);
void	solve(t_board *map);
int		min(int a, int b, int c);
int		count_size(char *argv);
char	*read_map_file(char *argv);
int		transfer_file(char *argv, t_board *board_info, int i);
int		transfer_file_stdin(char *buf, t_board *board_info, int i);
int		into_board(char *buf, t_board *board_info, int idx, int i);
int		into_board_check(char *buf, t_board *board_info, int idx);
int		ft_atoi_ht(char *buf, int i);
int		redun_check(t_board *board_info);
int		width_height(char *buf, t_board *board_info, int i, int j);
int		first_line(char *buf, t_board *board_info);
char	*parse_stdin(void);
void	free_map(t_board *map);
void	free_board(int **board, int height);
void	free_all(t_board *map);
#endif // !BSQ_H
