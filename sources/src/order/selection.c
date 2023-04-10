/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/10 18:41:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void	selection(t_stack **a, t_stack **b, t_data *data)
{
	int	chunks;

	if (data->size == 2)
		sa_sb(a, SA);
	else if (data->size == 3)
		sort_three(a);
	else if (data->size > 3 && data->size <= 5)
		sort_five(a, b);
	else if (data->size > 5 && data->size <= 100)
	{
		chunks = 6;
		push_biggest(a, b, data, chunks);
		print_lst((*b));
		// printf(RED "-----\n");
		pop_biggest(a, b, data, chunks);
		free_chunk(data->chunk, chunks);
	}
	else
	{
		chunks = 10;
		push_biggest(a, b, data, chunks);
		pop_biggest(a, b, data, chunks);
		free_chunk(data->chunk, chunks);
	}
}
