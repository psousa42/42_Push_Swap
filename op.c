/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:39:49 by psousa            #+#    #+#             */
/*   Updated: 2023/06/19 12:39:51 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_op(int *stack, char *msg)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = tmp;
	ft_putstr_fd(msg, 1);
	return (1);
}

int	r_op(int *stack, int size, char *msg)
{
	int	tmp;
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		tmp = stack[i];
		stack[i] = stack[i + 1];
		stack[i + 1] = tmp;
	}
	ft_putstr_fd(msg, 1);
	return (1);
}

int	rr_op(int *stack, int size, char *msg)
{
	int	tmp;
	int	i;

	i = size;
	while (--i != 0)
	{
		tmp = stack[i];
		stack[i] = stack[i - 1];
		stack[i - 1] = tmp;
	}
	ft_putstr_fd(msg, 1);
	return (1);
}

int	pa_op(t_data *data)
{
	int	i;

	data->a.size++;
	i = data->a.size - 1;
	while (i > 0)
	{
		data->a.stack[i] = data->a.stack[i - 1];
		i--;
	}
	data->a.stack[0] = data->b.stack[0];
	i = 0;
	if (data->b.size >= 1)
	{
		while (i < data->b.size - 1)
		{
			data->b.stack[i] = data->b.stack[i + 1];
			i++;
		}
	}
	data->b.size--;
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb_op(t_data *data)
{
	int	i;

	data->b.size++;
	i = data->b.size - 1;
	while (i > 0)
	{
		data->b.stack[i] = data->b.stack[i - 1];
		i--;
	}
	data->b.stack[0] = data->a.stack[0];
	i = 0;
	while (i < data->a.size - 1)
	{
		data->a.stack[i] = data->a.stack[i + 1];
		i++;
	}
	data->a.size--;
	ft_putstr_fd("pb\n", 1);
	return (1);
}

/*int    rr2_op(t_data *data)
{
	int        tmp;
	int        i;

	i = -1;
	while (++i < data->a.size - 1)
	{
		tmp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[i + 1];
		data->a.stack[i + 1] = tmp;
	}
	i = -1;
	while (++i < data->b.size - 1)
	{
		tmp = data->b.stack[i];
		data->b.stack[i] = data->b.stack[i + 1];
		data->b.stack[i + 1] = tmp;
	}
	ft_putstr_fd("rr\n", 1);
}*/

/*int    ss_op(t_data *data)
{
	int    tmp;
	int    i;

	i = 0;
	tmp = data->a.stack[i];
	data->a.stack[i] = data->a.stack[i + 1];
	data->a.stack[i + 1] = tmp;
	tmp = data->b.stack[i];
	data->b.stack[i] = data->b.stack[i + 1];
	data->b.stack[i + 1] = tmp;
	ft_putstr_fd("ss\n", 1);
}*/

/*int    rrr_op(t_data *data)
{
	int        tmp;
	int        i;

	i = data->a.size;
	while (--i != 0)
	{
		tmp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[i - 1];
		data->a.stack[i - 1] = tmp;
	}
	i = data->b.size;
	while (--i != 0)
	{
		tmp = data->b.stack[i];
		data->b.stack[i] = data->b.stack[i - 1];
		data->b.stack[i - 1] = tmp;
	}
	ft_putstr_fd("rrr\n", 1);
}*/
