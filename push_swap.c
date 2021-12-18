/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/18 16:01:40 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_free(char **nums, t_stack *stk_a)
{
	int	count;

	count = 0;
	while (nums[count])
	{
		free(nums[count]);
		count++;
	}
	free(nums);
	nums = NULL;
	stack_free(stk_a);
}

int	main(int argc, char **argv)
{
	char	**nums;
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		count;

	if (argc > 2)
	{
		nums = valid_helper(argc, argv);
		count = 0;
		while (nums[count])
			count++;
		stk_a = validate(count, nums);
		stk_a = indexation(stk_a);
		stk_b = from_a_to_b(&stk_a);
		stk_a = from_b_to_a(stk_a, stk_b);
		if (stk_a->ind != 0)
			rotate(&stk_a);
		final_free(nums, stk_a);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
