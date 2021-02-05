#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lmt.h"
#include "get_next_line.h"

int main()
{
	char	*line1;
	int		return_value1;

	while ((return_value1 = get_next_line(0, &line1)) == 1)
	{
		PRINT(line1, s);
		free(line1);
		line1 = NULL;
	}
	PRINT(return_value1, d);
	if (line1)
		PRINT(line1, s);
	return (0);
}
