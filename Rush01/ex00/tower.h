#define RIGHT 1
#define MASK 2047
extern int	g_grid[9][9];
extern int	g_size;
extern int	g_row_condition[9][2];
extern int g_col_condition[9][2];
extern int	g_row_candidates[9];
extern int	g_col_candidates[9];

#define __MAX_SIZE__ 9
void	copy_col(int board[][__MAX_SIZE__], int arr[], int y, int size);

void	copy_row(int board[][__MAX_SIZE__], int arr[], int x, int size);

void	reverse_arr(int arr[], int size);

void	print_board(int board[][__MAX_SIZE__], int size);

void	print_str(char *str);

int		solve(void);

#ifndef TOWER_H
#define TOWER_H
#ifndef LEFT
#define LEFT (0)
#endif // !LEFT
#endif