#include <unistd.h>

int		main(void)
{
	char	*test;
	int		i;

	i = 0;
	test = NULL;
	while (i < 10)
	{
		test[i] = 'a';
		i++;
	}
	return (0);
}
