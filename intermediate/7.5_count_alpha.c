#include<stdio.h>

void	count_alpha(char *s)
{
	int	a[128];
	int	i;
	int	x;

	i = 0;
	while (i < 128)
		a[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			a[(int)s[i] + 32] += 1;
		else if (s[i] >= 97 && s[i] <= 122)
			a[(int)s[i]] += 1;
		++i;
	}
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90 && a[(int)s[i] + 32])
		{
			if (x)
				printf(", ");
			printf("%d%c", a[(int)s[i] + 32], s[i] + 32);
			a[(int)s[i] + 32] = 0;
			x = 1;
		}
		else if (s[i] >= 97 && s[i] <= 122 && a[(int)s[i]])
		{
			if (x)
				printf(", ");
			printf("%d%c", a[(int)s[i]], s[i]);
			a[(int)s[i]] = 0;
			x = 1;
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
