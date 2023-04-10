/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/10 11:26:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void	print_tp(t_data *data)
{
	int	i;

	i = data->size - 1;
	while (i >= 0)
	{
		printf(ORANGE "%d :%d\n", data->tp[i], i);
		i--;
	}
}

void	print_lst(t_stack *num)
{
	while (num)
	{
		printf(CYAN "%d index: %d\n", num->num, num->index);
		num = num->next;
	}
}

void	print_lst_two(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	ft_printf(GREEN "----A----    ----B----\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf(YELLOW "   %d", tmp_a->num);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("     ");
		if (tmp_b)
		{
			ft_printf(CYAN "\t\t%d", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
}

//=========================================================================

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	*stack_a;
	t_stack	*stack_b;

	ctrl_num(argc - 1, argv);
	init_data(&data, argc - 1);
	stack_a = add_num(&data, argv);
	ctrl_num_dupl(&data);
	ctrl_sorted(&data);
	quick_sort(data.tp, 0, data.size - 1);
	index_stack(stack_a, data.tp, data.size);
	selection(&stack_a, &stack_b, &data);
	free(data.tp);
	free(data.chunk);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}

//=========================================================================
// printf(GREEN "----A----\n");
// print_lst(stack_a);
// printf(GREEN "----B----\n");
// print_lst(stack_b);
//=========================================================================
