/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/07 10:22:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_ps data;

	// ft_bzero(&data, sizeof(t_ps));
	data.stack_a = ft_calloc(argc, sizeof(int));
	data.stack_b = ft_calloc(argc, sizeof(int));
	data.len = argc - 1;

	add_num(&data, argv);
	ctrl_num_dupl(&data);

	int i = 0;
	while (i < argc - 1)
	{
		ft_printf(YELLOW " a:%d, b:%d\n", data.stack_a[i], data.stack_b[i]);
		i++;
	}
	free(data.stack_a);
	free(data.stack_b);
}
