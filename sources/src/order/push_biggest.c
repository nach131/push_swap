/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:21:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/10 18:45:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"
#include <math.h>

void static	init_chunk(t_data *data, int n)
{
	int	i;

	i = 0;
	data->chunk = ft_calloc(n, sizeof(int *));
	while (i < n)
	{
		data->chunk[i] = ft_calloc(3, sizeof(int));
		i++;
	}
}

void static	chunk(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
		{
			data->chunk[n - 1][START] = round(i * (data->size / n));
			data->chunk[n - 1][END] = data->size;
			data->chunk[i][MIDDLE] = round((data->chunk[i][START]
						+ data->chunk[i][END]) / 2);
		}
		else
		{
			data->chunk[i][START] = round(i * (data->size / n));
			data->chunk[i][END] = round((i + 1) * (data->size / n));
			data->chunk[i][MIDDLE] = round((data->chunk[i][START]
						+ data->chunk[i][END]) / 2);
		}
		i++;
	}
}

void static	sort_chunk_ex(t_stack **a, t_stack **b, t_data *data, int i)
{
	switch_tp(data->tp, (*a)->index - 1, ON);
	pa_pb(a, b, PB);
	if ((*a))
		if (((*b)->index <= data->chunk[i][MIDDLE])
			&& ((*a)->index > data->chunk[i][END]))
			rr(a, b);
	if (((*b)->index <= data->chunk[i][MIDDLE]) &&
		((*b)->index > data->chunk[i][START]))
		ra_rb(b, RB);
}

void static	sort_chunk(t_stack **a, t_stack **b, t_data *data, int n)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_reverse((*a));
	i = 0;
	while (i < n)
	{
		while (ctrl_tp(data->tp, data->chunk[i][START], data->chunk[i][END]
				- 1))
		{
			if (((*a)->index <= data->chunk[i][END]))
				sort_chunk_ex(a, b, data, i);
			if ((*a))
				if (((*a)->index > data->chunk[i][END]))
					ra_rb(a, RA);
			// clear_stack(tmp);
		}
		i++;
	}
}

void	push_biggest(t_stack **a, t_stack **b, t_data *data, int chunks)
{
	init_chunk(data, chunks);
	chunk(data, chunks);
	ft_bzero(data->tp, data->size * sizeof(int));
	sort_chunk(a, b, data, chunks);
}
