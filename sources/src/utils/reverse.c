/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:47:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/18 09:55:47 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

// desplaza hacia abajo todos los elementos del stack A una posición,
// de forma que el último elemento se convierte en el primero.

void rra(t_data *data)
{
	int i;

	t_num last;
	i = data->a.top - 1;
	if (data->a.top > 0)
	{
		last = data->a.stack[data->a.top];

		while (i >= 0)
		{
			swap_t(&data->a.stack[i], &data->a.stack[i + 1]);
			i--;
		}
		swap_t(&last, &data->a.stack[0]);
	}
	ft_printf("rra\n");
}

// Desplaza hacia abajo todos los elementos del stack B una posición,
// de forma que el último elemento se convierte en el primero.

void rrb(t_data *data)
{
	int i;

	t_num last;
	i = data->b.top - 1;
	if (data->b.top > 0)
	{
		last = data->b.stack[data->b.top];
		while (i >= 0)
		{
			swap_t(&data->b.stack[i], &data->b.stack[i + 1]);
			i--;
		}
		swap_t(&last, &data->b.stack[0]);
	}
	ft_printf("rrb\n");
}

void rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
