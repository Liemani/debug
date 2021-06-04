#include "t_lss.h"
#include "describe.h"

int	main(int argc, char **argv)
{
	t_lss	*p_lss;

	p_lss = new_lss(argc, argv);
	lss_run(p_lss);
	while (1);
	return (0);
}
