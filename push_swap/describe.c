#include <stdio.h>
#include "describe.h"
#include "t_lss.h"
#include "t_circular_list.h"
#include "t_node_lss.h"

void	lss_describe(t_lss *p_lss)
{
	circular_list_describe(&p_lss->list_a);
	circular_list_describe(&p_lss->list_b);
}

void	circular_list_describe(t_circular_list *p_list)
{
	int i;
	t_node_lss  *p_node;

	printf("[");
	p_node = p_list->p_dummy->p_next;
	i = 0;
	while (i < p_list->count)
	{
		node_lss_describe(p_node);
		p_node = p_node->p_next;
		++i;
	}
	printf("] \n");
}

void	node_lss_describe(t_node_lss *p_node)
{
	printf("%d, ", p_node->value);
}
