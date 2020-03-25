#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int	i = 0;
	int	j = 0;
	int	x = 0;
		
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			
			if (x)
				printf(" ");
			printf("%d", a[i]);
			x = 1;
			++i;
			++j;
		}
		else if (a[i] < b[j])
			++i;
		else
			++j;
	}
	printf("\n");
}

int	main(void)
{
	int	arr1[] = {1, 2, 10, 15};
	int	arr2[] = {2, 20, 40, 70};
	int	arr3[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int	arr4[] = {2, 4, 5, 6, 7, 10, 40, 70};
	int	arr5[] = {100, 200, 300};
	int	arr6[] = {1, 2, 3, 4};
	
	print_doublon(arr1, 4, arr2, 4);
	print_doublon(arr3, 11, arr4, 8);
	print_doublon(arr5, 3, arr6, 4);
	return (0);
}
