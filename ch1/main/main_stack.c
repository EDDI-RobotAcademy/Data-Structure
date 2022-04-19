#include <stdlib.h>

#include "stack.h"

int main (void)
{
	int *data;

	stack stack;
	stack_elem *top;

	stack_init(&stack, free);
	top = stack_top(&stack);

	for (int i = 0; i < 7; i++)
	{
		data = (int *)malloc(sizeof(int));
		*data = 10 * i;
		stack_push(&stack, data);
	}

	stack_print(&stack);

	return 0;
}
