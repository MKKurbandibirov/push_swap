/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/26 13:23:36 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int	max;
	int	min;

	init_stacks(stacks);
	stacks->stk_a = validator(argc, argv);
	stacks->len_a = stk_size(stacks->stk_a);
	max = -1;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val > max)
			max = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	min = 2147483647;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val < min)
			min = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	stacks->cur = stacks->stk_a;
	while (stacks->len_a > 2)
	{
		if (stacks->stk_a->val != min && stacks->stk_a->val != max)
			push_and_write(stacks, 'b');
		else
			rotate_and_write(stacks, 'a');
	}
	stacks->len_b = stk_size(stacks->stk_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate(&stacks, argc, argv);
	sort(&stacks);
	
	// while (stacks.stk_a)
	// {
	// 	printf("|%4d|\n", stacks.stk_a->val);
	// 	stacks.stk_a = stacks.stk_a->next;
	// }
	return (0);
}
