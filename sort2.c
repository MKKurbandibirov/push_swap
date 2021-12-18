/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:06:23 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/18 15:57:58 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_oper(t_stack *stk, int ind)
{
	int		oper;
	t_stack	*current;

	oper = 0;
	current = stk;
	while (current->ind != ind)
	{
		oper++;
		current = current->next;
	}
	if (oper > stk_size(stk) / 2)
		oper = stk_size(stk) - oper;
	return (oper);
}

t_pair	*find_best_pair(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*c_a;
	t_stack	*c_b;
	t_pair	*best_pair;

	best_pair = (t_pair *)malloc(sizeof(t_pair));
	if (!best_pair)
		return (NULL);
	c_a = stk_a;
	while (c_a)
	{
		c_b = stk_b;
		while (c_b)
		{
			if ((c_b->ind - c_a->ind) == 1 || (c_b->ind - c_a->ind) == -1)
			{
				best_pair->ind_a = c_a->ind;
				best_pair->ind_b = c_b->ind;
			}
			c_b = c_b->next;
		}
		c_a = c_a->next;
	}
	return (best_pair);
}

void	prepare_a_and_b(t_stack **s_a, t_stack **s_b, t_pair **pair)
{
	while ((*s_a)->ind != (*pair)->ind_a && (*s_b)->ind != (*pair)->ind_b)
	{
		rotate(s_a);
		rotate(s_b);
		write(1, "rr\n", 3);
	}
	while ((*s_a)->ind != (*pair)->ind_a)
	{
		rotate(s_a);
		write(1, "ra\n", 3);
	}
	while ((*s_b)->ind != (*pair)->ind_b)
	{
		rotate(s_b);
		write(1, "rb\n", 3);
	}
	if ((*pair)->ind_a < (*pair)->ind_b)
	{
		rotate(s_a);
		write(1, "ra\n", 3);
	}
}

t_stack	*from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	t_pair	*b_pair;

	while (stk_b)
	{
		b_pair = find_best_pair(stk_a, stk_b);
		prepare_a_and_b(&stk_a, &stk_b, &b_pair);
		push(&stk_a, &stk_b);
		write(1, "pa\n", 3);
		free(b_pair);
		b_pair = NULL;
	}
	return (stk_a);
}
