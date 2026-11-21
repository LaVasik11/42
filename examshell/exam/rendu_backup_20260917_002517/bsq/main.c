#include "bsq.h"

int main(int argc, char **argv)
{
	size_t	n;
	char	*str;
	getline(stdin, &n, &str);
	if (argc == 1)
	{
		if (execute_bsq(stdin))
			fprintf(stderr, "map error\n");
	}
	else
	{
		if (read_file(argv[1]))
			fprintf(stderr, "map error\n");
	}
	return (0);
}
