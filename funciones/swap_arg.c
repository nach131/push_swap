#include <stdio.h>
#include "../sources/libft/inc/ft_printf.h"
#include "../sources/libft/inc/libft.h"

#define MAX_STACK_SIZE 1000

int stack_a[MAX_STACK_SIZE];
int stack_b[MAX_STACK_SIZE];
int top_a = -1;
int top_b = -1;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int *stack, int *top, int value)
{
	if (*top >= MAX_STACK_SIZE - 1)
	{
		printf("Error: Stack overflow\n");
		return;
	}
	*top = *top + 1;
	stack[*top] = value;
}

int pop(int *stack, int *top)
{
	if (*top == -1)
	{
		printf("Error: Stack underflow\n");
		return -1;
	}
	int value = stack[*top];
	*top = *top - 1;
	return value;
}

void sa()
{
	if (top_a > 0)
	{
		swap(&stack_a[top_a], &stack_a[top_a - 1]);
	}
}

void sb()
{
	if (top_b > 0)
	{
		swap(&stack_b[top_b], &stack_b[top_b - 1]);
	}
}

void ss()
{
	sa();
	sb();
}

void pa()
{
	if (top_b >= 0)
	{
		int value = pop(stack_b, &top_b);
		push(stack_a, &top_a, value);
	}
}

void pb()
{
	if (top_a >= 0)
	{
		int value = pop(stack_a, &top_a);
		push(stack_b, &top_b, value);
	}
}

void ra()
{
	if (top_a > 0)
	{
		int value = pop(stack_a, &top_a);
		push(stack_a, &top_a, value);
	}
}

void rb()
{
	if (top_b > 0)
	{
		int value = pop(stack_b, &top_b);
		push(stack_b, &top_b, value);
	}
}

void rr()
{
	ra();
	rb();
}

void rra()
{
	if (top_a > 0)
	{
		int value = pop(stack_a, &top_a);
		int temp_top = top_a;
		while (temp_top >= 0)
		{
			push(stack_a, &temp_top, pop(stack_a, &temp_top));
		}
		push(stack_a, &top_a, value);
	}
}

void rrb()
{
	if (top_b > 0)
	{
		int value = pop(stack_b, &top_b);
		int temp_top = top_b;
		while (temp_top >= 0)
		{
			push(stack_b, &temp_top, pop(stack_b, &temp_top));
		}
		push(stack_b, &top_b, value);
	}
}

void rrr()
{
	rra();
	rrb();
}

int is_sorted(int stack_a[], int top_a)
{
	for (int i = 0; i < top_a - 1; i++)
	{
		if (stack_a[i] > stack_a[i + 1])
		{
			return 0; // el stack a no está ordenado
		}
	}
	return 1; // el stack a está ordenado
}
#include <stdio.h>

int main(int argc, char *argv[])
{
	// Insertar números en el stack a

	int n = 1;
	while (n < argc)
	{
		push(stack_a, &top_a, ft_atoi(argv[n]));
		n++;
	}

	// push(stack_a, &top_a, 3);
	// push(stack_a, &top_a, 1);
	// push(stack_a, &top_a, 4);
	// push(stack_a, &top_a, 2);

	int i = 0;
	while (i < 4)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	printf("-----\n");
	// Ejecutar operaciones de ordenamiento
	sa();
	pb();
	ra();
	// pb();
	sa();
	ra();
	// ra();
	pa();
	// pa();
	i = 0;
	while (i < 4)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	if (is_sorted(stack_a, top_a))
	{
		printf("El stack a está ordenado\n");
	}
	else
	{
		printf("El stack a no está ordenado\n");
	}
	if (top_b == -1)
	{
		printf("El stack b está vacío\n");
	}
	else
	{
		printf("El stack b no está vacío\n");
	}
	return 0;
}
