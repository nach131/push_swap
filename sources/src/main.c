/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/15 17:30:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void print_stack(t_ps stack)
{
	int i = 0;

	while (i <= stack.top)
	{
		printf(YELLOW "%d :%d\n", stack.stack[i], i);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;

	ctrl_num(argc - 1, argv);
	init_data(&data, argc - 1);
	add_num(&data, argv);

	// print_stack(data.a);
	quickSort(data.tp.stack, 0, data.size - 1);
	print_stack(data.tp);

	ctrl_num_dupl(&data);
	ctrl_sorted(&data);

	selection(&data);

	// write(1, "----\n", 5);
	// print_stack(data.a);

	// if (data.b.top > 0)
	// 	ft_printf(GREEN "----\n");
	// print_stack(data.b);
	// ft_printf(ORANGE "%d\n", data.count);

	free(data.a.stack);
	free(data.b.stack);
}
