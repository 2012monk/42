#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "tower.h"

#define COL 0
#define ROW 1

int	condition[9][2][2];
int	possible[9][2];
int	board[9][9];
int	SIZE;
int	MASK;

int	row_condition[9][2];
int col_condition[9][2];
void	print_nbr(int i, int j)
{
	char	c;

	while (j < SIZE)
	{
		c = '0' + board[i][j] % 10;
		write(1, &c, 1);
		if (j != SIZE - 1)
			write(1, " ", 1);
		// printf("%d", board[i][j]);
		j++;
	}
}

void	print_board(void)
{
	int	i;

	i = -1;
	while (++i < SIZE)
	{
		print_nbr(i, 0);
		write(1, "\n", 1);
		// printf("%c", '\n');
	}
}

int	count_boxes(int tab[SIZE])
{
	int	cnt;
	int	max;
	int	i;

	i = -1;
	max = 0;
	cnt = 0;
	while (++i < SIZE)
	{
		if (tab[i] && tab[i] > max)
		{
			cnt++;
			max = tab[i];
		}
	}
	return	(cnt);
}

void	copy_row(int arr[SIZE], int x)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		arr[i] = board[x][i];
}

void	copy_col(int arr[SIZE], int y)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		arr[i] = board[i][y];
}

void	rev_tab(int arr[SIZE])
{
	int	i;
	int	tmp;

	i = 0;
	while (i < SIZE / 2)
	{
		tmp = arr[i];
		arr[i] = arr[SIZE - i - 1];
		arr[SIZE - i - 1] = tmp;
		i++;
	}
}

int	check_row(int x, int y, int val)
{
	int ret;
	int	tab[9];
	
	if (y != SIZE - 1)
		return (1);
	copy_row(tab, x);
	tab[y] = val;
	ret = count_boxes(tab) == row_condition[x][0];
	rev_tab(tab);
	return (ret && count_boxes(tab) == row_condition[x][1]);
}

int	check_col(int x, int y, int val)
{
	int ret;
	int	tab[9];
	
	if (x != SIZE - 1)
		return (1);
	copy_col(tab, y);
	tab[x] = val;
	ret = count_boxes(tab) == col_condition[y][0];
	rev_tab(tab);
	return (ret && count_boxes(tab) == col_condition[y][1]);
}

int	validate_move(int x, int y, int val)
{
	return (check_row(x, y, val) && check_col(x, y, val));
}

void	find_unfilled(int *x, int *y)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (board[i][j] == 0)
			{
				*x = i;
				*y = j;
				return ;
			}
		}
	}
	*x = -1;
	*y = -1;
}

int	check_candidate(int x, int y, int val)
{
	return (!(possible[x][0] & (1 << val))
		&& !(possible[y][1] & (1 << val)));
}

int	flip_bit(int n)
{
	return MASK ^ (1 << n);
}

int	solve(void)
{
	int	x;
	int	y;
	int	c;

	find_unfilled(&x, &y);
	if (x == -1 || y == -1)
		return (1);
	c = 1;
	while (c <= SIZE)
	{
		// printf("%d %d %d val : %d %d\n", x, y, c, check_candidate(x, y, c), validate_move(x, y, c));
		if (check_candidate(x, y, c) && validate_move(x, y, c))
		{
			// print_board();
			board[x][y] = c;
			possible[x][0] |= 1 << (c);
			possible[y][1] |= 1 << (c);
			if (solve())
				return (1);
			board[x][y] = 0;
			possible[x][0] &= flip_bit(c);
			possible[y][1] &= flip_bit(c);
		}
		c++;
	}
	return (0);
}

int	fatoi(char c)
{
	return (c - '0');
}

void	setup_input(int size, char const **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (j < SIZE)
	{
		col_condition[i%SIZE][0] = fatoi(arr[j][0]);
		i++;
		j++;
	}
	i = 0;
	while (j < SIZE * 2)
	{
		col_condition[i%SIZE][1] = fatoi(arr[j][0]);
		i++;
		j++;
	}
	i = 0;
	while (j < SIZE * 3)
	{
		row_condition[i%SIZE][0] = fatoi(arr[j][0]);
		i++;
		j++;
	}
	i = 0;
	while (j < size)
	{
		row_condition[i%SIZE][1] = fatoi(arr[j][0]);
		i++;
		j++;
	}
}

void	init()
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		possible[i][0] = 0;
		possible[i][1] = 0;
		j = -1;
		while (++j < SIZE)
			board[i][j] = 0;
	}
}

int	ft_sqrt(int nb)
{
	int	lo;
	int	hi;
	int	mid;
	int	ret;

	lo = 1;
	hi = nb;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid <= nb / mid)
		{
			lo = mid + 1;
			ret = mid;
		}
		else
			hi = mid - 1;
	}
	return (ret);
}

int main(int argc, char const **argv)
{
	init();
	SIZE = (argc - 1) / 4;
	MASK = (1 << (SIZE + 1)) - 1;
	// printf("%d", SIZE);
	// col_condition[0][0] = 4;
	// col_condition[0][1] = 1;
	// col_condition[1][0] = 3;
	// col_condition[1][1] = 2;
	// col_condition[2][0] = 2;
	// col_condition[2][1] = 2;
	// col_condition[3][0] = 1;
	// col_condition[3][1] = 2;

	// row_condition[0][0] = 4;
	// row_condition[0][1] = 1;
	// row_condition[1][0] = 3;
	// row_condition[1][1] = 2;
	// row_condition[2][0] = 2;
	// row_condition[2][1] = 2;
	// row_condition[3][0] = 1;
	// row_condition[3][1] = 2;
	setup_input(argc - 1, argv + 1);

	// for (int i=0;i<4;i++)
	// {
	// 	printf("%d ", col_condition[i][0]);
	// }
	// for (int i=0;i<4;i++)
	// {
	// 	printf("%d ", col_condition[i][1]);
	// }
	// for (int i=0;i<4;i++)
	// {
	// 	printf("%d ", row_condition[i][0]);
	// }
	// for (int i=0;i<4;i++)
	// {
	// 	printf("%d ", row_condition[i][1]);
	// }
	
	if (solve())
		print_board();
	else
		write(1, "no solution error", 17);
	// printf("%d\n", 0 | (1 << 3));
	// printf("%d", 15& MASK&(~(1<<3)));
	return 0;
}
