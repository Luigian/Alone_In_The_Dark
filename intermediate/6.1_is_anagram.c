#include <stdio.h>

int	is_anagram(char *a, char *b)
{
	int	arr[128];
	int	i;

	i = 0;
	while (i < 128)
		arr[i++] = 0;
	i = 0;
	while (a[i])
	{
		arr[(int)a[i]] += 1;
		++i;
	}
	i = 0;
	while (b[i])
	{
		arr[(int)b[i]] -= 1;
		++i;
	}
	i = 0;
	while (i < 128)
	{
		if (arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", is_anagram("cinema", "iceman"));
	return (0);
}	
