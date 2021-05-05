#include <stdio.h>
#include "describe.h"
#include "value_type.h"
#include "object.h"

void	vector3_describe(t_vector3 vector)
{
	printf("(%f, %f, %f) \n", vector[X], vector[Y], vector[Z]);
}

void	matrix3_describe(t_matrix3 matrix)
{
	printf("(%f, %f, %f) \n", matrix[X][X], matrix[X][Y], matrix[X][Z]);
	printf("(%f, %f, %f) \n", matrix[Y][X], matrix[Y][Y], matrix[Y][Z]);
	printf("(%f, %f, %f) \n", matrix[Z][X], matrix[Z][Y], matrix[Z][Z]);
}

void	circle_describe(t_geometry *p_geometry)
{
	t_circle *const	p_circle = p_geometry->p_derived_object;

	printf("circle: \n");
	printf("center: ");
	vector3_describe(p_circle->center);
	printf("normal: ");
	vector3_describe(p_circle->normal);
	printf("basis_vector: \n");
	matrix3_describe(p_circle->basis_vector);
	printf("radius: %f \n", p_circle->radius);
}
