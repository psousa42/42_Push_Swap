/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:41:25 by psousa            #+#    #+#             */
/*   Updated: 2023/06/19 12:41:26 by psousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack{
	int		*stack;
	int		*clone;
	int		*index;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_data{
	t_stack	a;
	t_stack	b;
}	t_data;

long	long_atoi(const char *str);
void	ft_error(t_data *data);
void	init(t_data *data, int argc);
void	gertudes(t_data *data);
void	is_digit(char *argv, t_data *data);
void	cck(int argc, char **argv, t_data *data);
void	dub(t_data *data);
int		is_sorted(t_data *data);
int		s_op(int *stack, char *msg);
int		r_op(int *stack, int size, char *msg);
int		rr_op(int *stack, int size, char *msg);
int		pa_op(t_data *data);
int		pb_op(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	radix(t_data *data, int size);
void	op_r500(t_data *data, int size);
void	op_pb500(t_data *data);
void	op_pa500(t_data *data);

#endif
