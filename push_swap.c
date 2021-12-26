/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomed <magomed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/26 19:58:55 by magomed          ###   ########.fr       */
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

void	sort_for_3(t_list *list)
{
	int el_1;
	int el_2;
	int el_3;

	el_1 = list->val;
	el_2 = list->next->val;
	el_3 = list->next->next->val;
	if (el_1 > el_2 && el_2 > el_3 && el_1 > el_3)
	{
		swap(&list);
		reverse_rotate(&list);
		write (1, "sa\nrra\n", 7);
	}
	if (el_1 > el_2 && el_2 < el_3 && el_1 < el_3)
	{
		swap(&list);
		write (1, "sa\n", 3);
	}
	if (el_1 > el_2 && el_2 < el_3 && el_1 > el_3)
	{
		rotate(&list);
		write(1, "ra\n", 3);
	}
	if (el_1 < el_2 && el_2 > el_3 && el_1 < el_3)
	{
		swap(&list);
		rotate(&list);
		write(1, "sa/nra/n", 6);
	}
	if (el_1 < el_2 && el_3 > el_1 && el_1 > el_3)
	{
		reverse_rotate(&list);
		write (1, "rra\n", 4);
	}
}

void	validate(t_stacks *stacks, int argc, char **argv)
{
	int	max;
	int	min;
	char		**nums;
	int			count;

	nums = valid_helper(argc, argv);
	count = 0;
	while (nums[count])
		count++;
	if (count == 1)
		exit(EXIT_SUCCESS);
	if (count == 2 && stacks->stk_a->val > stacks->stk_a->next->val)
	{
		swap(&(stacks->stk_a));
		write (1, "sa\n", 3);
	}
	if (count == 3)
		sort_for_3(stacks->stk_a);
	if (count > 3 && count < 6)
	{
		push_and_write(stacks, 'b');
		if (stacks->len_a == 4)
			push_and_write(stacks, 'b');
		sort_for_3(stacks->stk_a);
		sort(stacks);
	}
		
	init_stacks(stacks);
	stacks->stk_a = validator(count, nums);
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

int is_sorted(t_list *list)
{
	t_list *cur;
	
	cur = list;
	while (cur->next)
	{
		if (cur->val > cur->next->val)
		{
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate(&stacks, argc, argv);
	if (is_sorted(stacks.stk_a))
		return (0);
	sort(&stacks);
	
	// while (stacks.stk_a)
	// {
	// 	printf("|%4d|\n", stacks.stk_a->val);
	// 	stacks.stk_a = stacks.stk_a->next;
	// }
	return (0);
}
