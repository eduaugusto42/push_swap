#include <stdio.h>
#include "input.h"
#include "benchmark.h"

int	main(int argc, char **argv)
{
  t_input *input;

  input = parse_command_line(argc, argv);
  if (argc == 1)
    return (0);
  if (compute_disorder(input) == 0)
    return (0);
	if (!parse_command_line(argc, argv))
	{
		printf("Error\n");
		return (1);
	}

	printf("Input accepted\n");
	return (0);
}