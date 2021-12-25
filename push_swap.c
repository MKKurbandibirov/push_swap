/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/25 17:22:37 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	finale_rotate(t_stacks *stacks)
{
	int	min;
	int	min_pos;

	min = 2147483647;
	min_pos = 0;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val < min)
			min = stacks->cur->val;
		stacks->cur = stacks->cur->next;
		min_pos++;
	}
	if (min_pos > stacks->len_a / 2)
	{
		while (stacks->stk_a->val != min)
			rev_rotate_and_write(stacks, 'a');
	}
	else
	{
		while (stacks->stk_a->val != min)
			rotate_and_write(stacks, 'a');
	}
}

void	init_stacks(t_stacks *st)
{
	st->stk_a = NULL;
	st->stk_b = NULL;
	st->cur = NULL;
	st->min_op = 0;
	st->method_v = 0;
	st->len_a = 0;
	st->len_b = 0;
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

void	validate(t_stacks *stacks, int argc, char **argv)
{
	char		**nums;
	int			count;

	nums = valid_helper(argc, argv);
	count = 0;
	while (nums[count])
		count++;
	if (count < 2)
	{
		exit (1);
	}
	init_stacks(stacks);
	stacks->stk_a = validator(count, nums);
	while (stacks->stk_a->next)
		push_and_write(stacks, 'b');
	stacks->len_a = stk_size(stacks->stk_a);
	stacks->len_b = stk_size(stacks->stk_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate(&stacks, argc, argv);
	sort(&stacks);
	// getchar();
	return (0);
}
