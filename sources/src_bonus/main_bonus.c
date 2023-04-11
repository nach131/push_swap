/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/11 16:48:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../libft/inc/get_next_line.h"
#include "push_swap_bonus.h"

// void	print_lst(t_stack *num)
// {
// 	while (num)
// 	{
// 		printf(CYAN "%d \n", num->num);
// 		num = num->next;
// 	}
// }

//=========================================================================

void	print_lst_two(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	system("clear");
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

void	filter(t_stack **a, t_stack **b, char *order)
{
	if (!ft_strncmp(order, "sa\n", 3))
		sa_sb(a);
	else if (!ft_strncmp(order, "sb\n", 3))
		sa_sb(b);
	else if (!ft_strncmp(order, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(order, "pa\n", 3))
		pa_pb(a, b, PA);
	else if (!ft_strncmp(order, "pb\n", 3))
		pa_pb(a, b, PB);
	else if (!ft_strncmp(order, "ra\n", 3))
		ra_rb(a);
	else if (!ft_strncmp(order, "rb\n", 3))
		ra_rb(b);
	else if (!ft_strncmp(order, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(order, "rra\n", 3))
		rra_rrb(a);
	else if (!ft_strncmp(order, "rrb\n", 3))
		rra_rrb(b);
	else if (!ft_strncmp(order, "rrr\n", 3))
		rrr(a, b);
	else
		ctrl_order(a, b);
	print_lst_two((*a), (*b));
}

void	get_line(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		filter(a, b, line);
		if (line)
			free(line);
	}
}

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
	stack_b = NULL;
	get_line(&stack_a, &stack_b);
	ctrl_sorted_user(stack_a);
	free(data.tp);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
