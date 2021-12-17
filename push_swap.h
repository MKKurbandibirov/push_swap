/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:53:33 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/17 11:45:00 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define ERR_CODE -2147483649
# define EMPTY_IND -1
# define TRUE 1
# define FALSE -1
# define NONE 0

typedef struct s_stack
{
	int				content;
	int				index;
	int				keep_in_a;
	struct s_stack	*next;
}	t_stack;

t_stack	*validate(int argc, char **argv);

t_stack	*crt_new_elm(int content);
t_stack	*stk_push_back(t_stack *stk, int content);
t_stack	*stk_copy(t_stack *stk);
void	stack_free(t_stack *stk_push_back);

void	swap(t_stack **stk);
void	push(t_stack **stk_1, t_stack **stk_2);
void	rotate(t_stack **stk);
void	reverse_rotate(t_stack **stk);

int		stk_size(t_stack *stk_a);
int		*get_indexes(t_stack *stk_a);
t_stack	*indexation(t_stack *stk_a);

int		find_markup_head_ind(t_stack *stk_a);
t_stack	*markup(t_stack *stk);

int		swap_is_needed(t_stack **stk);
t_stack	*from_a_to_b(t_stack **stk_a);
#endif