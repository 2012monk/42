/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:03:26 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 21:34:45 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tower.h"

int	get_intput_length(char *arr)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (arr[i])
	{
		while ((arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t'))
			i++;
		if (!arr[i])
			return (cnt);
		if ('0' <= arr[i] && arr[i] <= 'z')
		{
			if (i != 0 && !(arr[i - 1] == ' ' || arr[i - 1] == '\n'
					|| arr[i - 1] == '\t'))
				return (-1);
			cnt++;
		}
		else
			return (-1);
		i++;
	}
	if ('0' <= arr[i - 1] && arr[i - 1] <= 'z')
		return (cnt);
	return (-1);
}

int	setup_input(t_status *status, char *arr)
{
	int	i;
	int	j;
	int	x;
	int	v;

	i = 0;
	j = 0;
	while (arr[j])
	{
		if ('0' <= arr[j] && arr[j] <= '9')
		{
			x = i % status->size;
			v = arr[j] - '0';
			if (i < (status->size * 2))
				status->col_constraints[x][i / status->size] = v;
			else
				status->row_constraints[x][i / (status->size * 3)] = v;
			i++;
		}
		j++;
	}
	return (i);
}

void	initialize_status(t_status *status)
{
	int	i;
	int	j;

	i = -1;
	while (++i < status->size)
	{
		status->col_candidates[i] = 0;
		status->row_candidates[i] = 0;
		j = -1;
		while (++j < status->size)
			status->grid[i][j] = 0;
	}
}

int	main(int argc, char **argv)
{
	t_status	*status;
	int			lenght;

	if (argc != 2)
	{
		print_str("Error\n");
		return (1);
	}
	lenght = get_intput_length(argv[1]);
	if (lenght <= 4 || lenght % 4 != 0)
	{
		print_str("Error\n");
		return (1);
	}
	status = malloc(sizeof(t_status));
	status->size = lenght / 4;
	initialize_status(status);
	setup_input(status, argv[1]);
	if (solve(status))
		print_board(status->grid, status->size);
	else
		print_str("Error\n");
	free(status);
	return (0);
}
