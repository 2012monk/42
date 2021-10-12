#include <stdio.h>

void	swap(int *i, int *j);

void	ft_rev_int_tab(int *tab, int size);

int main()
{
	int arr[] = {5, 4, 3, 2, 1, 0};
	ft_rev_int_tab(arr, 6);
	for (int i=0;i<6;i++)
		printf("%d ", arr[i]);
	return 0;
}
