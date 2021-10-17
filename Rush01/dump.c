
// int	check_row(int x, int y, int val)
// {
// 	int ret;
// 	int	tab[9];
	
// 	if (y != SIZE - 1)
// 		return (1);
// 	copy_row(tab, x);
// 	tab[y] = val;
// 	ret = count_boxes(tab) == row_condition[x][0];
// 	reverse_arr(tab);
// 	return (ret && count_boxes(tab) == row_condition[x][1]);
// }

// int	check_col(int x, int y, int val)
// {
// 	int ret;
// 	int	tab[9];
	
// 	if (x != SIZE - 1)
// 		return (1);
// 	copy_col(board, tab, y);
// 	tab[x] = val;
// 	ret = count_boxes(tab) == col_condition[y][0];
// 	reverse_arr(tab);
// 	return (ret && count_boxes(tab) == col_condition[y][1]);
// }
