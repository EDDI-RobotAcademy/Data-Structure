#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef struct _stack_method
{
	void (* destroy) (void *data);
}
stack_method;

typedef struct _stack_elem
{
	void *data;
	struct _stack_elem *node;
}
stack_elem;

typedef struct _stack
{
	int size;
	stack_elem *top;

	stack_method *func;
}
stack;

stack_method *stack_method_table;

stack_method *stack_method_init (void);
void stack_init(stack *stack, void (*destroy)(void *data));
stack_elem *create_stack_node(void);
void stack_push(stack *stack, void *data);
void stack_print(stack *stack);

#define stack_top(node)                 ((node)->top)

#ifdef __cplusplus
}
#endif

#endif
