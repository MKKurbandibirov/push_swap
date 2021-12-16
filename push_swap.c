/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:46:57 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/16 14:14:32 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack		**stk_a;
	t_stack		**stk_b;
	// t_stack		**cpy_a;
	// (void) argc;
	// (void) **argv;

	stk_a = (t_stack **)malloc(sizeof(t_stack *));
	// cpy_a = (t_stack **)malloc(sizeof(t_stack *));
	// *cpy_a = validate(argc, argv);
	*stk_a = validate(argc, argv);
	// *stk_a = indexation(*stk_a);
	// *stk_a = markup(*stk_a);
	
	// while (*cpy_a)
	// {
	// 	printf("%12d -> %3d -> %3d\n", (*cpy_a)->content, (*cpy_a)->index, (*cpy_a)->keep_in_a);
	// 	*cpy_a = (*cpy_a)->next;
	// }
	// printf("\n");
	// swap(stk_a);
	// *stk_a = markup(*stk_a);
	// rotate(stk_a);
	// swap(stk_a);
	// *stk_a = markup(*stk_a);
	// while (*stk_a)
	// {
	// 	printf("%12d -> %3d -> %3d\n", (*stk_a)->content, (*stk_a)->index, (*stk_a)->keep_in_a);
	// 	*stk_a = (*stk_a)->next;
	// }

	// push(cpy_a, stk_a);
	// push(cpy_a, stk_a);
	// push(cpy_a, stk_a);
	// push(cpy_a, stk_a);
	// while (*cpy_a)
	// {
	// 	printf("%d ", (*cpy_a)->content);
	// 	*cpy_a = (*cpy_a)->next;
	// }
	// printf("\n");
	// while (*stk_a)
	// {
	// 	printf("%d ", (*stk_a)->content);
	// 	*stk_a = (*stk_a)->next;
	// }
	
	// while (*cpy_a)
	// {
	// 	printf("%d ", (*cpy_a)->content);
	// 	*cpy_a = (*cpy_a)->next;
	// }
	// rotate(stk_a);
	// rotate(stk_a);
	// rotate(stk_a);
	// printf("\n");
	// while (*stk_a)
	// {
	// 	printf("%d ", (*stk_a)->content);
	// 	*stk_a = (*stk_a)->next;
	// }
	
	// *stk_a = crt_new_elm(345);
	// while (*cpy_a)
	// {
	// 	printf("%d ", (*cpy_a)->content);
	// 	*cpy_a = (*cpy_a)->next;
	// }
	// reverse_rotate(stk_a);
	// reverse_rotate(stk_a);
	// reverse_rotate(stk_a);
	// printf("\n");
	// while (*stk_a)
	// {
	// 	printf("%d ", (*stk_a)->content);
	// 	*stk_a = (*stk_a)->next;
	// }
	
	// int *arr = get_indexes(*stk_a);
	// for (int i = 0; i < stk_size(*stk_a); i++)
	// {
	// 	printf("%d ", arr[i]);
	// }

	// *stk_a = indexation(*stk_a);
	// while (*stk_a)
	// {
	// 	printf("%d -> %d\n", (*stk_a)->content, (*stk_a)->index);
	// 	*stk_a = (*stk_a)->next;
	// }
	// printf("\n\n");
	// *cpy_a = indexation(*cpy_a);
	// int markup_head_ind = find_markup_head_ind(*cpy_a);
	// printf ("%d", markup_head_ind);
	
	// *stk_a = indexation(*stk_a);
	// *stk_a = markup(*stk_a);
	// while (*stk_a)
	// {
	// 	printf("%d -> %d -> %d\n", (*stk_a)->content, (*stk_a)->index, (*stk_a)->keep_in_a);
	// 	*stk_a = (*stk_a)->next;
	// }
	
	// *stk_a = indexation(*stk_a);
	// int g = swap_is_needed(stk_a);
	// printf("\n%d\n", g);
	
	*stk_a = indexation(*stk_a);
	stk_b = from_a_to_b(stk_a);
	printf("\n\n");
	while (*stk_a)
	{
		printf("%12d -> %3d -> %3d\n", (*stk_a)->content, (*stk_a)->index, (*stk_a)->keep_in_a);
		*stk_a = (*stk_a)->next;
	}
	printf("\n");
	while (*stk_b)
	{
		printf("%12d -> %3d -> %3d\n", (*stk_b)->content, (*stk_b)->index, (*stk_b)->keep_in_a);
		*stk_b = (*stk_b)->next;
	}
	printf("\n");

	return (0);
}
