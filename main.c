#include "input.h"
#include "stack.h"
#include <stdio.h>

static void print_strategy(t_strategy strategy)
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

static void print_stack(t_stack *stack)
{
	t_node	*current;
	int		i;

	printf("\n===== STACK A =====\n");
	printf("size: %d\n", stack->size);

	current = stack->top;
	i = 0;
	while (current)
	{
		printf("[%d] value = %d | index = %d\n",
			i, current->value, current->index);
		current = current->next;
		i++;
	}

	if (stack->top)
		printf("top = %d\n", stack->top->value);
	if (stack->bottom)
		printf("bottom = %d\n", stack->bottom->value);
	printf("===================\n");
}

int	main(int argc, char **argv)
{
	t_input	*input;
	t_stack	stack;

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

	stack_init(&stack);
	stack_fill_from_array(&stack, input->numbers, input->size);

	printf("\nANTES DO RA\n");
  print_stack(&stack);

  ra(&stack);

  printf("\nDEPOIS DO RA\n");
  print_stack(&stack);

	stack_clear(&stack);
	free_input(input);
	return (0);
}