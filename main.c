#include "input.h"
#include <stdio.h>

static void	print_strategy(t_strategy strategy)
{
	if (strategy == SIMPLE)
		printf("strategy: SIMPLE\n");
	else if (strategy == MEDIUM)
		printf("strategy: MEDIUM\n");
	else if (strategy == COMPLEX)
		printf("strategy: COMPLEX\n");
	else if (strategy == ADAPTIVE)
		printf("strategy: ADAPTIVE\n");
	else
		printf("strategy: INVALID\n");
}

int	main(int argc, char **argv)
{
	t_input	*input;
	int		i;

	if (argc == 1)
		return (0);
	input = parse_command_line(argc, argv);
	if (!input)
	{
		printf("Erro no parser\n");
		return (1);
	}

	printf("Quantidade de numeros: %d\n", input->size);
	print_strategy(input->strategy);
	printf("benchmark: %d\n", input->benchmark);

	i = 0;
	while (i < input->size)
	{
		printf("numbers[%d] = %d\n", i, input->numbers[i]);
		i++;
	}

	free_input(input);
	return (0);
}