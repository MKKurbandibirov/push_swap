/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:18:48 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/18 11:14:01 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*crt_new_elm(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->ind = EMPTY_IND;
	new->keep_in_a = NONE;
	new->next = NULL;
	return (new);
}

t_stack	*stk_push_back(t_stack *stk, int content)
{
	t_stack	*current;

	if (!stk)
	{
		stk = crt_new_elm(content);
		return (stk);
	}
	current = stk;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (t_stack *)malloc(sizeof(t_stack));
	if (!current->next)
		return (NULL);
	current->next->content = content;
	current->next->ind = EMPTY_IND;
	current->keep_in_a = NONE;
	current->next->next = NULL;
	return (stk);
}

t_stack	*stk_copy(t_stack *stk)
{
	t_stack	*copy;
	t_stack	*current;

	copy = NULL;
	current = stk;
	while (current)
	{
		copy = stk_push_back(copy, current->content);
		if (!copy)
			return (NULL);
		current = current->next;
	}
	copy = indexation(copy);
	copy = markup(copy);
	return (copy);
}

void	stack_free(t_stack *stk)
{
	t_stack	*current;

	while (stk)
	{
		current = stk;
		free(current);
		stk = stk->next;
	}
	free(stk);
	stk = NULL;
}
