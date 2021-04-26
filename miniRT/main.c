#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "t_matrix3.h"
#include "t_vector3.h"
#include "util.h"

int	main(void)
{
	t_vector3	camera_normalized_orientation = {1.0, 1.0, 1.0};
	vector3_normalize(camera_normalized_orientation);
	const t_matrix3	*camera_standard_unit_vector = matrix3_standard_unit_vector(&camera_normalized_orientation);

	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			printf("%f, ", ((*camera_standard_unit_vector)[i][j]));
			++j;
		}
		printf("\n");
		++i;
	}

	return (0);
}
