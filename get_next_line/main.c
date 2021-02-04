#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lmt.h"
#include "get_next_line.h"

int main()
{
	int 	fd1;
	int 	fd2;
	char	*line1;
	char	*line2;
	int		return_value1;
	int		return_value2;

	fd1 = open("empty_file.txt", O_RDONLY);
	fd2 = open("marge_even.txt", O_RDONLY);
	PRINT(fd1, d);
	PRINT(fd2, d);
	while ((return_value1 = get_next_line(fd1, &line1)) == 1
		&& (return_value2 = get_next_line(fd2, &line2)) == 1)
	{
		PRINT(line1, s);
		PRINT(line2, s);
		free(line1);
		free(line2);
		line1 = NULL;
		line2 = NULL;
	}
	PRINT(return_value1, d);
	PRINT(return_value2, d);
	if (line1)
		PRINT(line1, s);
	if (line2)
		PRINT(line2, s);
	close(fd1);
	close(fd2);
	return (0);
}
