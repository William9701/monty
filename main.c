#include "monty.h"

stack_t* stack = NULL;
int main(int argc, char *argv[])
{
	char opcode[50];
	unsigned int line_number = 0;
	FILE *bytecode_file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecode_file = fopen(argv[1], "r");
	if (bytecode_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(bytecode_file, "%s", opcode) == 1)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(bytecode_file, "%u", &line_number) != 1)
			{
				fprintf(stderr, "Error: Missing argument for push opcode.\n");
				fclose(bytecode_file);
				return (1);
			}
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L %u: unknown instruction %s.\n", line_number, opcode);
			fclose(bytecode_file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(bytecode_file);
	return (0);
}
