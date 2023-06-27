/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:40:11 by psousa            #+#    #+#             */
/*   Updated: 2023/06/19 12:40:13 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->a.size)
	{
		j = 0;
		while (data->a.stack[i] != data->a.clone[j])
			j++;
		if (data->a.stack[i] == data->a.clone[j])
			data->a.index[i] = j + 1;
		i++;
	}
}

void	dup_sort(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i != data->a.size)
	{
		data->a.clone[i] = data->a.stack[i];
		data->a.index[i] = data->a.stack[i];
	}
	i = -1;
	while (++i != data->a.size)
	{
		j = i;
		while (++j != data->a.size)
		{
			if (data->a.clone[i] > data->a.clone[j])
			{
				tmp = data->a.clone[i];
				data->a.clone[i] = data->a.clone[j];
				data->a.clone[j] = tmp;
			}
		}
	}
	ft_index(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 2)
	{
		data = malloc(sizeof(t_data));
		init(data, argc);
		cck(argc, argv, data);
		if (is_sorted(data) == 0)
			return (0);
		dup_sort(data);
		if (argc == 4)
			sort_three(data);
		else if (argc == 5)
			sort_four(data);
		else if (argc == 6)
			sort_five(data);
		else
			radix(data, data->a.size);
		free(data->a.stack);
		free(data->b.stack);
		free(data->a.index);
		free(data->a.clone);
		free(data->b.index);
		free(data->b.clone);
		free(data);
	}
	return (0);
}
