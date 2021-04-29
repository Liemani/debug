#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "t_matrix3.h"
#include "t_vector3.h"
#include "util.h"

int	main(void)
{
	t_vector3	normalized_orientation = {0.01, 0.0, -1.0};
	vector3_normalize(normalized_orientation);
	const t_matrix3	standard_unit_vector;
	matrix3_standard_unit_vector(&normalized_orientation, standard_unit_vector);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			printf("%.10lf, ", (standard_unit_vector[i][j]));
		printf("\n");
	}

	t_vector3 some_vector = {0.0, 0.0, -1.0};
	vector3_multiply_matrix3(some_vector, standard_unit_vector);
	for (int i = 0; i < 3; ++i)
		printf("%.10lf, ", some_vector[i]);
	printf("\n");

	return (0);
}
