/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:04:37 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 12:42:42 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	method_1(t_stacks *st)
{
	int	op_do;

	op_do = min(st->pos_a, st->pos_b);
	while (op_do--)
		rotate_and_write(st, 'r');
	op_do = diff(st->pos_a, st->pos_b);
	if (st->pos_a > st->pos_b)
	{
		while (op_do--)
			rotate_and_write(st, 'a');
	}
	else if (st->pos_a < st->pos_b)
	{
		while (op_do--)
			rotate_and_write(st, 'b');
	}
	push_and_write(st, 'a');
}

void	method_2(t_stacks *st)
{
	int	op_do;

	op_do = st->pos_a;
	while (op_do--)
		rotate_and_write(st, 'a');
	op_do = st->len_b - st->pos_b;
	while (op_do--)
		rev_rotate_and_write(st, 'b');
	push_and_write(st, 'a');
}

void	method_3(t_stacks *st)
{
	int	op_do;

	op_do = st->pos_b;
	while (op_do--)
		rotate_and_write(st, 'b');
	op_do = st->len_a - st->pos_a;
	while (op_do--)
		rev_rotate_and_write(st, 'a');
	push_and_write(st, 'a');
}

void	method_4(t_stacks *st)
{
	int	op_do;

	op_do = min(st->len_a - st->pos_a, st->len_b - st->pos_b);
	while (op_do--)
		rev_rotate_and_write(st, 'r');
	op_do = diff(st->len_a - st->pos_a, st->len_b - st->pos_b);
	if (st->len_a - st->pos_a > st->len_b - st->pos_b)
	{
		while (op_do--)
			rev_rotate_and_write(st, 'a');
	}
	else if (st->len_a - st->pos_a < st->len_b - st->pos_b)
	{
		while (op_do--)
			rev_rotate_and_write(st, 'b');
	}
	push_and_write(st, 'a');
}
