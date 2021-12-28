/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 19:05:31 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	len_checker(t_stacks *stacks, int count)
{
	if (is_sorted(stacks->stk_a))
		return ;
	else if (count == 1)
	{
		stack_free(stacks->stk_a);
		exit(EXIT_SUCCESS);
	}
	else if (count == 2 && stacks->stk_a->val > stacks->stk_a->next->val)
		swap_and_write(stacks);
	else if (count == 3)
		sort_for_3(stacks);
}

static void	validate(t_stacks *stacks, int argc, char **argv)
{
	char	**nums;
	int		count;

	nums = valid_helper(argc, argv);
	count = 0;
	while (nums[count])
		count++;
	init_stacks(stacks);
	stacks->stk_a = validator(count, nums);
	stacks->len_a = stk_size(stacks->stk_a);
	stacks->len_b = stk_size(stacks->stk_b);
	len_checker(stacks, count);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate(&stacks, argc, argv);
	if (is_sorted(stacks.stk_a))
	{
		stack_free(stacks.stk_a);
		return (0);
	}
	start_push_b(&stacks);
	sort_for_3(&stacks);
	sort(&stacks);
	stack_free(stacks.stk_a);
	return (0);
}
