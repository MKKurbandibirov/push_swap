/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:53:33 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 12:42:44 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define ERR_CODE -2147483649

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*stk_a;
	t_list	*stk_b;
	t_list	*cur;
	int		pos_a;
	int		len_a;
	int		pos_b;
	int		len_b;
	int		method_v;
	int		min_op;
	int		i;
}	t_stacks;

char	**ft_split(char const *s, char c);
char	**valid_helper(int argc, char **argv);

t_list	*validator(int argc, char **argv);

t_list	*crt_new_elm(int val);
t_list	*stk_push_back(t_list *stk, int val);
t_list	*stk_copy(t_list *stk);
void	stack_free(t_list *stk);
int		stk_size(t_list *stk_a);

void	swap(t_list **stk);
void	push(t_list **stk_1, t_list **stk_2);
void	rotate(t_list **stk);
void	reverse_rotate(t_list **stk);

int		max(int a, int b);
int		min(int a, int b);
int		abs(int a);
int		diff(int a, int b);

void	set_pos_b(t_stacks *st, int i);

void	method_1(t_stacks *ob);
void	method_2(t_stacks *ob);
void	method_3(t_stacks *ob);
void	method_4(t_stacks *ob);

void	rotate_and_write(t_stacks *stacks, int c);
void	rev_rotate_and_write(t_stacks *stacks, int c);
void	push_and_write(t_stacks *stacks, int c);
void	swap_and_write(t_stacks *stacks);

void	start_push_b(t_stacks *stacks);

void	finale_rotate(t_stacks *stacks);
void	sort(t_stacks *stacks);
void	sort_for_3(t_stacks *stacks);
int		is_sorted(t_list *list);

void	init_stacks(t_stacks *st);
#endif