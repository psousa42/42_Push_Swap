/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:48:52 by psousa            #+#    #+#             */
/*   Updated: 2023/06/15 12:49:29 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_digit(char *argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' && i == 0)
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			ft_error(data);
		i++;
	}
}

void	dub(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i != data->a.size)
	{
		k = i + 1;
		while (k != data->a.size)
		{
			if (data->a.stack[i] == data->a.stack[k])
				ft_error(data);
			k++;
		}
		i++;
	}
}

void	cck(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	data->a.size = argc - 1;
	i = 0;
	while (++i < data->a.size)
		is_digit(argv[i], data);
	i = -1;
	j = 1;
	while (++i < data->a.size)
	{
		data->a.stack[i] = long_atoi(argv[j++]);
		if (data->a.stack[i] < INT_MIN || data->a.stack[i] > INT_MAX)
			ft_error(data);
	}
	dub(data);
	gertudes(data);
}

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a.size - 1)
	{
			if (data->a.stack[i] > data->a.stack[i + 1])
				return (1);
		i++;
	}
	return (0);
}

int	finder(t_data *data, int numb)
{
	int	pos_num;

	pos_num = 0;
	while (pos_num != data->b.size)
	{
		if (data->b.stack[pos_num] == numb)
		{
			return (pos_num);
		}
		pos_num++;
	}
	return (pos_num);
}
