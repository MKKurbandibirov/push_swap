/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:05:19 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/16 14:34:43 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	int		fls_cnt_untill;
	int		fls_cnt_after;
	// t_stack	**copy;
	// t_stack	*current;

	// copy = (t_stack **)malloc(sizeof(t_stack *));
	// if (!copy)
	// 	return (NULL);
	// current = *stk;
	// while (current)
	// {
		
	// }
	*stk = markup(*stk);
	fls_cnt_untill = stk_false_checker(*stk);
	swap(stk);
	*stk = markup(*stk);
	fls_cnt_after = stk_false_checker(*stk);
	if (fls_cnt_untill <= fls_cnt_after)
	{
		swap(stk);
		return (0);
	}
	return (1);
}

t_stack	**from_a_to_b(t_stack **stk_a)
{
	t_stack	**stk_b;

	stk_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stk_b)
		return (NULL);
	*stk_a = markup(*stk_a);
	while (stk_false_checker(*stk_a))
	{
		if (swap_is_needed(stk_a))
		{
			*stk_a = markup(*stk_a);
			write (1, "sa\n", 3);
		}
		if ((*stk_a)->keep_in_a == FALSE)
		{
			push(stk_b, stk_a);
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
