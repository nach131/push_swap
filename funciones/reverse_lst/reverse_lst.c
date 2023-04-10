/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:09:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/10 13:37:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#define LEN 10

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	new->num = value;
	new->index = -1;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*item;

	if (!stack)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		item = stack_last(*stack);
		item->next = new;
	}
}

t_stack	*add_num(int *tp)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 1;
	j = LEN - 1;
	while (j >= 0)
	{
		if (i == 1)
			stack = stack_new(tp[j]);
		else
			stackadd_back(&stack, stack_new(tp[j]));
		i++;
		j--;
	}
	return (stack);
}
void	print_lst(t_stack *num)
{
	while (num)
	{
		printf("%d index: %d\n", num->num, num->index);
		num = num->next;
	}
}

void	stack_reverse(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;
	t_stack	*prev;

	curr = *stack;
	if (!curr || !curr->next)
		return ;
	tmp = NULL;
	prev = NULL;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*stack = prev;
}

int	main(void)
{
	int		tp[9];
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	tp[0] = 0;
	tp[1] = 1;
	tp[2] = 2;
	tp[3] = 3;
	tp[4] = 4;
	tp[5] = 5;
	tp[6] = 6;
	tp[7] = 7;
	tp[8] = 8;
	a = add_num(tp);
	print_lst(a);
	stack_reverse(&a);
	printf("----------\n");
	print_lst(a);
	return (0);
}
