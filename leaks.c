#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	while (1)
	{
		sleep(5);
		system("clear");
		system("leaks 21sh");
	}
}
