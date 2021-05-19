#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "describe.h"
#include "value_type.h"
#include "object.h"
#include "util.h"
#include "get_line.h"
#include "../lmt.h"

#define EXECUTE test002

void	test002()
{
	const int rt_file = open("minimalist.rt", O_RDONLY);

	if (rt_file == -1)
	{
		printf("open error \n");
		exit(READ_ERROR);
	}

	t_line_buffer line_buffer;

	line_buffer_set(&line_buffer);
	while (get_line(rt_file, &line_buffer) == LINE_EXIST)
	{
		PRINT(line_buffer.p_line, s);
		free(line_buffer.p_line);
	}

	close(rt_file);
}

void	test001()
{
	t_geometry	*p_geometry = new_cylinder();
	t_cylinder	*p_cylinder = p_geometry->p_derived_object;

	cylinder_set_center(p_geometry, -2.0, 2.0, -3.0);
	cylinder_set_orientation(p_geometry, 1.0, -1.0, 1.0);
	cylinder_set_radius(p_geometry, 0.5);
	cylinder_set_height(p_geometry, 1);
	cylinder_set_circle_center(p_geometry);
	p_geometry->color = new_rgb32(0xb0, 0xb0, 0x40);

	printf("front ");
	circle_describe(p_cylinder->p_front);
	putchar('\n');
	printf("rear ");
	circle_describe(p_cylinder->p_rear);
}

void	test000()
{
	t_vector3	normalized_orientation = {0.01, 0.0, -1.0};
	vector3_normalize(normalized_orientation);
	const t_matrix3	standard_unit_vector;
	matrix3_basis_vector(&normalized_orientation, standard_unit_vector);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			printf("%.10lf, ", (standard_unit_vector[i][j]));
		printf("\n");
	}

	t_vector3 some_vector = {0.0, 0.0, -1.0};
	vector3_to_space(some_vector, standard_unit_vector);
	for (int i = 0; i < 3; ++i)
		printf("%.10lf, ", some_vector[i]);
	printf("\n");
}

int		main(void)
{
	EXECUTE();

	return (0);
}
