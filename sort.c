/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:40:24 by psousa            #+#    #+#             */
/*   Updated: 2023/06/19 12:40:25 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	if (data->a.stack[0] != data->a.min && data->a.stack[2] == data->a.max)
		s_op(data->a.stack, "sa\n");
	else if (data->a.stack[0] == data->a.max && data->a.stack[2] == data->a.min)
	{
		s_op(data->a.stack, "sa\n");
		rr_op(data->a.stack, data->a.size, "rra\n");
	}
	else if (data->a.stack[0] == data->a.max && data->a.stack[2] != data->a.min)
		r_op(data->a.stack, data->a.size, "ra\n");
	else if (data->a.stack[0] == data->a.min && data->a.stack[2] != data->a.max)
	{
		s_op(data->a.stack, "sa\n");
		r_op(data->a.stack, data->a.size, "ra\n");
	}
	else if (data->a.stack[0] != data->a.max && data->a.stack[2] == data->a.min)
		rr_op(data->a.stack, data->a.size, "rra\n");
}

void sort_four(t_data *data)
{
	int i;

	i = 0;
	while (data->a.stack[0] != data->a.min)
		r_op(data->a.stack, data->a.size, "ra\n");
	pb_op(data);
	gertudes(data);
	sort_three(data);
	pa_op(data);	
}

void	sort_five(t_data *data)
{
	int		i;

	i = 0;
	while (data->a.stack[0] && i < 2)
	{
		if (data->a.stack[0] != data->a.max && data->a.stack[0] != data->a.min)
			r_op(data->a.stack, data->a.size, "ra\n");
		else if (data->a.stack[0] == data->a.max || \
		data->a.stack[0] == data->a.min)
		{
			pb_op(data);
			i = i + 1;
		}
	}
	if (data->b.stack[0] != data->a.max)
		r_op(data->b.stack, data->b.size, "rb\n");
	gertudes(data);
	sort_three(data);
	pa_op(data);
	r_op(data->a.stack, data->a.size, "ra\n");
	if (data->b.size > 0)
		pa_op(data);
}

void	radix(t_data *data, int size)
{
	int	max_num;
	int	max_bits;
	int	j;
	int	i;
	int	num;

	max_num = data->a.size;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = data->a.index[0];
			if (((num >> i) & 1) == 1)
				op_r500(data, data->a.size);
			else
				op_pb500(data);
		}
		while (data->b.size != 0)
			op_pa500(data);
	}
}
