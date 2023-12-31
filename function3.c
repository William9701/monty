#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: Line number where the mul function is called.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *last;

	(void) stack;
	(void) line_number;
	if (command->stack_length < 2)
		return;

	tmp = command->head;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			last = tmp;
			break;
		}
		tmp = tmp->next;
	}

	last->prev->next = NULL;
	last->next = command->head;
	last->prev = NULL;

	command->head = last;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	command->stack = 1;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the sub function is called.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (command->stack_length < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_args();
		exit(EXIT_FAILURE);
	}
	temp1 = command->head;
	temp2 = temp1->next;

	temp2->n = temp2->n - temp1->n;
	delete_stack_node();
	command->stack_length -= 1;

}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (command->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_args();
		exit(EXIT_FAILURE);
	}

	temp1 = command->head;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	command->head = temp2;
}


/**
 * is_number - Checks if a string represents a valid integer number.
 * @str: The string to check.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
