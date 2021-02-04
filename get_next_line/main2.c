#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lmt.h"
#include "get_next_line.h"

int main()
{
	int 	fd1;
	char	*line1;
	int		return_value1;

	fd1 = open("data/marge_even.txt", O_RDONLY);
	PRINT(fd1, d);
	while ((return_value1 = get_next_line(fd1, &line1)) == 1)
	{
		PRINT(line1, s);
		free(line1);
		line1 = NULL;
	}
	PRINT(return_value1, d);
	if (line1)
		PRINT(line1, s);
	close(fd1);
	return (0);
}
