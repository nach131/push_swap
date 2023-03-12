/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/12 21:49:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void selection(t_data *data)
{
	if (data->size == 2)
		sa(data);
	else if (data->size == 3)
		order_three(data);
	else if (data->size > 3 && data->size <= 5)
		ft_printf(BGRED "mas de 2 menos de 5\n");
	else
		quickSort(data->a.stack, 0, data->size - 1);
}
