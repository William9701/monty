#include "monty.h"

stack_t* stack = NULL;
int main(int argc, char *argv[])
{
	char line[100];
	unsigned int line_number = 0;
	FILE *bytecode_file;
	unsigned int value;
	char *value_str;
	char *command;

	if (argc != 2)
	{
		dprintf(2,"Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecode_file = fopen(argv[1], "r");
	if (bytecode_file == NULL)
	{
		dprintf(2,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), bytecode_file) != NULL)
	{
		line_number++;
		command = strtok(line, " \t\n");
		value_str = strtok(NULL, " \t\n");
		if (command != NULL)
		{
			if (strcmp(command, "push") == 0)
			{
				if (value_str != NULL)
				{
					if (sscanf(value_str, "%u", &value) != 1)
					{
						dprintf(2,"L%u: usage: push integer\n", line_number);
						fclose(bytecode_file);
						exit(EXIT_FAILURE);
					}
					
					push(&stack, value);
				}
			}
			else if (strcmp(command, "pall") == 0)
			{
				pall(&stack, line_number);
			}
		}
		else
		{
			dprintf(2,"L%u: unknown instruction %s.\n", line_number, command);
			fclose(bytecode_file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(bytecode_file);
	return (0);
}
