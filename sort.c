/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:05:19 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/17 11:46:41 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_false_checker(t_stack *stk)
{
	t_stack	*current;
	int		count;

	current = stk;
	count = 0;
	while (current)
	{
		if (current->keep_in_a == FALSE)
			count++;
		current = current->next;
	}
	return (count);
}

int	swap_is_needed(t_stack **stk)
{
	t_stack	*copy;
	int		fls_cnt_untill;
	int		fls_cnt_after;

	copy = stk_copy(*stk);
	fls_cnt_untill = stk_false_checker(copy);
	swap(&copy);
	copy = markup(copy);
	fls_cnt_after = stk_false_checker(copy);
	if (fls_cnt_untill <= fls_cnt_after)
	{
		stack_free(copy);
		return (0);
	}
	stack_free(copy);
	return (1);
}

t_stack	*from_a_to_b(t_stack **stk_a)
{
	t_stack	*stk_b;

	stk_b = NULL;
	*stk_a = markup(*stk_a);
	while (stk_false_checker(*stk_a))
	{
		if (swap_is_needed(stk_a))
		{
			swap(stk_a);
			*stk_a = markup(*stk_a);
			write (1, "sa\n", 3);
		}
		else if ((*stk_a)->keep_in_a == FALSE)
		{
			push(&stk_b, stk_a);
			write (1, "pb\n", 3);
		}
		else
		{
			rotate(stk_a);
			write (1, "ra\n", 3);
		}
	}
	return (stk_b);
}
