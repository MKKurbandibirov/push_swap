/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:25:51 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/27 12:05:21 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stacks *stacks)
{
	int	min;

	min = 2147483647;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val < min)
			min = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	return (min);
}

static int	find_max(t_stacks *stacks)
{
	int		max;

	max = -1;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val > max)
			max = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	return (max);
}

void	start_push_b(t_stacks *stacks)
{
	int		max;
	int		min;

	max = find_max(stacks);
	min = find_min(stacks);
	stacks->cur = stacks->stk_a;
	while (stacks->len_a > 2)
	{
		if (stacks->stk_a->val != min && stacks->stk_a->val != max)
			push_and_write(stacks, 'b');
		else
			rotate_and_write(stacks, 'a');
	}
}
