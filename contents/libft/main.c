#include "lmt.h"
#include "libft.h"

#define SAVARG	"--save"

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (0);
	PRINT(argv[1], s);
	result = ft_memcmp(argv[1], SAVARG, ft_strlen(SAVARG));
	PRINT(result, d);
	return (0);
}
