// main_stdin.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../lmt.h"
#include "get_next_line.h"

int main()
{
	char	*line;
	int		return_value;

	while ((return_value = get_next_line(0, &line)) == 1)
	{
		PRINT(return_value, d);
		PRINT(line, s);
		free(line);
		line = NULL;
	}
	PRINT(return_value, d);
	if (line)
		PRINT(line, s);
	return (0);
}
