#include "bsq.h"


int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (execute_bsq(stdin))
			fprintf(stderr, "map error\n");
	}
	else
	{
		if (open_file(argv[1]))
			fprintf(stderr, "map error\n");
	}
	return (0);
}
