#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

stack_method *stack_method_init (void)
{
	stack_method *tmp = (stack_method *)malloc(sizeof(stack_method));
	tmp->destroy = NULL;

	return tmp;
}

void stack_init(stack *stack, void (*destroy)(void *data))
{
	stack_method_table = stack_method_init();
	stack_method_table->destroy = destroy;

	stack->size = 0;
	stack->func = stack_method_table;
	stack->top = NULL;

	return;
}

stack_elem *create_stack_node(void)
{
	stack_elem *tmp = (stack_elem *)malloc(sizeof(stack_elem));
	return tmp;
}

void stack_push(stack *stack, void *data)
{
	stack_elem *tmp = stack->top;

	stack->top = create_stack_node();
	stack->top->data = data;
	stack->top->node = tmp;
	stack->size++;
}

void stack_print(stack *stack)
{
	int *data;
	stack_elem *tmp = stack->top;

	while (tmp)
	{
		data = tmp->data;
		printf("stack: %3d\n", *data);

		tmp = tmp->node;
	}
}
