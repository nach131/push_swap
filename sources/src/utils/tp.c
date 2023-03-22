/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:57:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/22 23:06:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void switch_tp(int tp[], int n, int type)
{
	if (type)
		tp[n] = 1;
	if (!type)
		tp[n] = 0;
}

int tp_is_act(int tp[], int n)
{
	if (tp[n] == 1)
		return (1);
	return (0);
}

int ctrl_pb(int tp[], int star, int end)
{
	while (star <= end)
	{
		// printf(YELLOW "%d\n", star);
		if (tp[star] == 0)
			return (1);
		star++;
	}
	return (0);
}
