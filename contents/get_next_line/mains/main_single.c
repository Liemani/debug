// main_single.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../lmt.h"
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		return_value;

	fd = open("data/korean.txt", O_RDONLY);
	while ((return_value = get_next_line(fd, &line)) == 1)
	{
		PRINT(line, s);
		free(line);
		line = NULL;
	}
	PRINT(return_value, d);
	if (line)
		PRINT(line, s);
	return (0);
}
