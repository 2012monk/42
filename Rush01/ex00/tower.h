/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:45:51 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 10:45:53 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWER_H
# define TOWER_H

# define __MAX_SIZE__ 9

# define RIGHT 1

# define LEFT 0

# define MASK 2047

typedef struct s_status
{
	int	row_constraints[__MAX_SIZE__][2];
	int	col_constraints[__MAX_SIZE__][2];
	int	row_candidates[__MAX_SIZE__];
	int	col_candidates[__MAX_SIZE__];
	int	grid[__MAX_SIZE__][__MAX_SIZE__];
	int	size;
}	t_status;

void	copy_col(int board[][__MAX_SIZE__], int arr[], int y, int size);

void	copy_row(int board[][__MAX_SIZE__], int arr[], int x, int size);

void	reverse_arr(int arr[], int size);

void	print_board(int board[][__MAX_SIZE__], int size);

void	print_str(char *str);

int		solve(t_status *status);

int		is_used_box(int x, int y, int value, t_status *status);

void	delete_box(int x, int y, int value, t_status *status);

void	place_box(int x, int y, int value, t_status *status);

#endif
