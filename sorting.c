/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:10:18 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 14:47:58 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finale_rotate(t_stacks *stacks)
{
	int	min;
	int	min_pos;
	int	tmp_pos;

	min = 2147483647;
	min_pos = 0;
	tmp_pos = 0;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val < min)
		{
			min = stacks->cur->val;
			min_pos = tmp_pos;
		}
		stacks->cur = stacks->cur->next;
		tmp_pos++;
	}
	if (min_pos > stacks->len_a / 2)
		while (stacks->stk_a->val != min)
			rev_rotate_and_write(stacks, 'a');
	else
		while (stacks->stk_a->val != min)
			rotate_and_write(stacks, 'a');
}

void	sort(t_stacks *stacks)
{
	while (stacks->stk_b)
	{
		set_pos_b(stacks, 0);
		if (stacks->method_v == 1)
			method_1(stacks);
		else if (stacks->method_v == 2)
			method_2(stacks);
		else if (stacks->method_v == 3)
			method_3(stacks);
		else if (stacks->method_v == 4)
			method_4(stacks);
	}
	finale_rotate(stacks);
}

void	sort_for_3(t_stacks *stacks)
{
	int	el_1;
	int	el_2;
	int	el_3;

	el_1 = stacks->stk_a->val;
	el_2 = stacks->stk_a->next->val;
	el_3 = stacks->stk_a->next->next->val;
	if (el_1 > el_2 && el_2 > el_3 && el_1 > el_3)
	{
		swap_and_write(stacks);
		rev_rotate_and_write(stacks, 'a');
	}
	else if (el_1 > el_2 && el_2 < el_3 && el_1 < el_3)
		swap_and_write(stacks);
	else if (el_1 > el_2 && el_2 < el_3 && el_1 > el_3)
		rotate_and_write(stacks, 'a');
	else if (el_1 < el_2 && el_2 > el_3 && el_1 < el_3)
	{
		swap_and_write(stacks);
		rotate_and_write(stacks, 'a');
	}
	else if (el_1 < el_2 && el_2 > el_1 && el_1 > el_3)
		rev_rotate_and_write(stacks, 'a');
}

int	is_sorted(t_list *list)
{
	t_list	*cur;

	cur = list;
	while (cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}
