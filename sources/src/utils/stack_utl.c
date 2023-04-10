/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:46 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/10 17:25:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

int	len_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_small(t_stack *stack)
{
	int	num;

	num = stack->index;
	while (stack && stack->next)
	{
		if (num > stack->next->index)
			num = stack->next->index;
		stack = stack->next;
	}
	return (num);
}

int	find_big(t_stack *stack)
{
	int	num;

	num = stack->index;
	while (stack && stack->next)
	{
		if (num < stack->next->index)
			num = stack->next->index;
		stack = stack->next;
	}
	return (num);
}

int	last_index(t_stack *stack)
{
	int	num;

	if (!stack)
		return (0);
	while (stack)
	{
		num = stack->index;
		stack = stack->next;
	}
	return (num);
}

t_stack	*stack_reverse(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*new_head;
	t_stack	*new_node;

	if (!stack || !stack->next)
		return (stack);
	curr = stack;
	new_head = NULL;
	while (curr)
	{
		new_node = stack_new(curr->num);
		new_node->index = curr->index;
		new_node->next = new_head;
		new_head = new_node;
		curr = curr->next;
	}
	return (new_head);
}

//=========================================================================

// int	first_index(t_stack *stack)
// {
// 	return (stack->index);
// }
