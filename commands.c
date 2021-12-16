/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:30:35 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/16 14:17:13 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stk)
{
	t_stack	*first;
	t_stack	*second;

	if (stk && (*stk)->next)
	{
		first = *stk;
		second = (*stk)->next;
		first->next = second->next;
		second->next = first;
		*stk = second;
	}
}

void	push(t_stack **stk_1, t_stack **stk_2)
{
	t_stack	*head_2;

	if (!*stk_2)
		return ;
	head_2 = *stk_2;
	*stk_2 = (*stk_2)->next;
	if (!*stk_1)
	{
		*stk_1 = head_2;
		head_2->next = NULL;
		return ;
	}
	head_2->next = *stk_1;
	*stk_1 = head_2;
}

void	rotate(t_stack **stk)
{
	t_stack	*head;
	t_stack	*current;

	if (*stk && (*stk)->next)
	{
		head = *stk;
		*stk = (*stk)->next;
		current = *stk;
		while (current->next)
		{
			current = current->next;
		}
		current->next = head;
		current->next->next = NULL;
	}
}

void	reverse_rotate(t_stack **stk)
{
	t_stack	*current;
	t_stack	*last;

	if (*stk && (*stk)->next)
	{
		current = *stk;
		while (current->next->next)
		{
			current = current->next;
		}
		last = current->next;
		current->next = NULL;
		last->next = *stk;
		*stk = last;
	}
}
