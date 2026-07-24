#include <stdio.h>
#include "input.h"
#include "benchmark.h"
#include "stack.h"
#include "algorithm.h"

int	main(int argc, char **argv)
{
	t_input *input;
	t_stack	*a;
	t_stack	*b;

	stack_init(a);
	stack_init(b);
	input = parse_command_line(argc, argv);
	if (argc == 1)
		return (0);
	if (input->disorder == 0)
		return (0);
	if (!parse_command_line(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	if (input->disorder <= 0.2)
		sort_simple(a, b, stats, input);

	printf("Input accepted\n");
	return (0);
}