/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomed <magomed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:58:29 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/29 13:24:13 by magomed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos_a(t_stacks *st, int v)
{
	t_list	*c;
	int		i;

	c = st->stk_a;
	st->pos_a = 0;
	i = 0;
	while (c->next)
	{
		if (v > c->val && v < c->next->val)
			st->pos_a = i + 1;
		else if (v < c->val && v < c->next->val && c->val > c->next->val)
			st->pos_a = i + 1;
		else if (v > c->val && c->next->val && c->val > c->next->val)
			st->pos_a = i + 1;
		i++;
		c = c->next;
	}
	if (v > c->val && v < st->stk_a->val)
		st->pos_a = st->len_a;
}

void	choose_method(t_stacks *st)
{
	int	count_op;

	st->min_op = max(st->pos_a, st->pos_b);
	st->method_v = 1;
	count_op = st->pos_a + (st->len_b - st->pos_b);
	if (count_op < st->min_op)
	{
		st->min_op = count_op;
		st->method_v = 2;
	}
	count_op = st->pos_b + (st->len_a - st->pos_a);
	if (count_op < st->min_op)
	{
		st->min_op = count_op;
		st->method_v = 3;
	}
	count_op = max(st->len_a - st->pos_a, st->len_b - st->pos_b);
	if (count_op < st->min_op)
	{
		st->min_op = count_op;
		st->method_v = 4;
	}
	st->min_op++;
}

void	norm_helper(t_stacks *st, int method_v, int pos_a, int pos_b)
{
	st->method_v = method_v;
	st->pos_a = pos_a;
	st->pos_b = pos_b;
}

void	set_pos_b(t_stacks *st, int i)
{
	int	method_v;
	int	min;
	int	pos_b;
	int	pos_a;

	min = 2147483647;
	st->cur = st->stk_b;
	while (st->cur)
	{
		st->pos_b = i;
		set_pos_a(st, st->cur->val);
		choose_method(st);
		if (st->min_op < min)
		{
			min = st->min_op;
			pos_b = i;
			pos_a = st->pos_a;
			method_v = st->method_v;
		}
		i++;
		st->cur = st->cur->next;
	}
	st->min_op = min;
	norm_helper(st, method_v, pos_a, pos_b);
}
