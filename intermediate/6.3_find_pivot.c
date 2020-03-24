#include <stdio.h>

int	find_pivot(int	*arr, int n)
{
	int	i;
	int	total;
	int	left;

	i = 0;
	total = 0;
	left = 0;
	while (i < n)
		total += arr[i++];
	i = 0;
	while (i < n)
	{
		left += arr[i];
		if ((total - left) == (left - arr[i]))
				return (i);
		++i;
	}
	return (-1);
}

int	main(void)
{
	int	arr1[] = {1, 2, 3, 4, 0, 6};
	int	arr2[] = {-5, 10, 2, 5};
	int	arr3[] = {1, 100, 0, 0, 1};
	int	arr4[] = {7, 9, 8};
	int	arr5[] = {1, 2};

	printf("%d\n", find_pivot(arr1, 6));
	printf("%d\n", find_pivot(arr2, 4));
	printf("%d\n", find_pivot(arr3, 5));
	printf("%d\n", find_pivot(arr4, 3));
	printf("%d\n", find_pivot(arr5, 2));
	return (0);
}
