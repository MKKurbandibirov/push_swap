/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:18:48 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/25 14:52:33 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*crt_new_elm(int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}

t_list	*stk_push_back(t_list *stk, int val)
{
	t_list	*current;

	if (!stk)
	{
		stk = crt_new_elm(val);
		return (stk);
	}
	current = stk;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (t_list *)malloc(sizeof(t_list));
	if (!current->next)
		return (NULL);
	current->next->val = val;
	current->next->next = NULL;
	return (stk);
}

t_list	*stk_copy(t_list *stk)
{
	t_list	*copy;
	t_list	*current;

	copy = NULL;
	current = stk;
	while (current)
	{
		copy = stk_push_back(copy, current->val);
		if (!copy)
			return (NULL);
		current = current->next;
	}
	return (copy);
}

void	stack_free(t_list *stk)
{
	t_list	*current;

	while (stk)
	{
		current = stk;
		stk = stk->next;
		free(current);
	}
	free(stk);
	stk = NULL;
}

int	stk_size(t_list *stk_a)
{
	t_list	*current;
	int		size;

	current = stk_a;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
