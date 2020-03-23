#include <stdio.h>

void	equation(int n)
{
	int	a[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
	int	bc;
	int	i;

	i = 0;
	while (i < 10)
	{
		bc = n - a[i];
		if (bc >= 0 && bc < 100)
			printf("A = %d, B = %d, C = %d\n", i, bc % 10, bc / 10);
		i++;
	}
}

int	main(void)
{
	equation(42);
	printf("\n");
	equation(111);
	printf("\n");
	equation(0);
	return (0);
}
