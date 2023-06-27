/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:40:54 by psousa            #+#    #+#             */
/*   Updated: 2023/06/19 12:40:55 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	long_atoi(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

void	init(t_data *data, int argc)
{
	data->a.stack = malloc(sizeof(int) * (argc - 1));
	data->a.size = 0;
	data->b.stack = malloc(sizeof(int) * (argc - 1));
	data->b.size = 0;
	data->a.max = 0;
	data->a.min = 0;
	data->a.index = malloc(sizeof(int) * (argc - 1));
	data->a.clone = malloc(sizeof(int) * (argc - 1));
	data->b.index = malloc(sizeof(int) * (argc - 1));
	data->b.clone = malloc(sizeof(int) * (argc - 1));
}

void	gertudes(t_data *data)
{
	int	i;

	i = -1;
	data->a.min = data->a.stack[0];
	while (++i < data->a.size)
	{
		if (data->a.min > data->a.stack[i])
			data->a.min = data->a.stack[i];
	}
	i = -1;
	data->a.max = data->a.stack[0];
	while (++i < data->a.size)
	{
		if (data->a.max < data->a.stack[i])
			data->a.max = data->a.stack[i];
	}
}

void	ft_error(t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	free(data->a.stack);
	free(data->b.stack);
	free(data->a.index);
	free(data->a.clone);
	free(data->b.index);
	free(data->b.clone);
	free(data);
	exit(1);
}
