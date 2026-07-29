#include "input.h"
#include "stack.h"
#include "algorithm.h"
#include "benchmark.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_input	*input;
	t_stats	*stats;
  t_algorithm *alg;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
  alg = init_algorithm();
  alg->a = a;
  alg->b = b;
	input = parse_command_line(argc, argv);
	if (!input)
	{
		printf("Error\n");
		return (1);
	}
	stack_fill_from_array(&a, input->numbers, input->size);
	stats = init_stats();
	if (input->disorder == 0)
		return (0);
	if (input->disorder <= 0.2)
		sort_simple(alg);
	print_banch(input, stats);
	return (0);
}