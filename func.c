#include "monty.h"

/**
 * push - push
 * @stack: stack
 * @line_number: line_number
 */
void push(stack_t **stack, unsigned int line_number)
{
	/*int value;*/
	stack_t *new_node;
	/**
	if (fscanf(bytecode_file, "%d", &value) != 1)
	{
		fprintf(stderr, "Error: Missing argument for push opcode on line %u.\n", line_number);
		exit(EXIT_FAILURE);
	}
	*/

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
 * pall - pall
 * @stack: stack
 * @line_number: line_number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
