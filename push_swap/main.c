#include "t_lss.h"
#include "describe.h"

int	main(int argc, char **argv)
{
	t_lss	*p_lss;

	p_lss = new_lss(argc, argv);
	circular_list_describe(&p_lss->list_a);
	circular_list_describe(&p_lss->list_b);
	lss_run(p_lss);
	circular_list_describe(&p_lss->list_a);
	circular_list_describe(&p_lss->list_b);
	return (0);
}
