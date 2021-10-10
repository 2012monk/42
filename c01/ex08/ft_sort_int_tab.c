/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:09:37 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 18:10:08 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	partion(int *arr, int lo, int hi)
{
	int	pivot;
	int	i;

	i = lo;
	pivot = arr[hi];
	while (i < hi)
	{
		if (pivot > arr[i])
			swap(&arr[lo++], &arr[i]);
		i++;
	}
	swap(&arr[lo], &arr[hi]);
	return (lo);
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot_i;

	if (left >= right)
		return ;
	pivot_i = partion(arr, left, right);
	quick_sort(arr, left, pivot_i - 1);
	quick_sort(arr, pivot_i + 1, right);
}

void	ft_sotr_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size);
}

// int main(int argc, char const *argv[])
// {
// 	int a[] = {9,8,7,6,5,4,4,2,1,0};
// 	int *ptr = a;
// 	ft_sotr_int_tab(ptr, 9);
// 	for (int i=0;i<10;i++){
// 		printf("%d ", ptr[i]);
// 	}
// 	return 0;
// }