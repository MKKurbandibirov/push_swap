/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:30:35 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 12:42:37 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stk)
{
	t_list	*first;
	t_list	*second;

	if (stk && (*stk)->next)
	{
		first = *stk;
		second = (*stk)->next;
		first->next = second->next;
		second->next = first;
		*stk = second;
	}
}

void	push(t_list **stk_1, t_list **stk_2)
{
	t_list	*head_2;

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

void	rotate(t_list **stk)
{
	t_list	*head;
	t_list	*current;

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

void	reverse_rotate(t_list **stk)
{
	t_list	*current;
	t_list	*last;

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
