/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomed <magomed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:18:48 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/15 19:25:26 by magomed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*crt_new_elm(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = EMPTY_IND;
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
	current->next = malloc(sizeof(t_stack));
	if (!current->next)
		return (NULL);
	current->next->content = content;
	current->next->index = EMPTY_IND;
	current->keep_in_a = NONE;
	current->next->next = NULL;
	return (stk);
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
	stk = NULL;
}
