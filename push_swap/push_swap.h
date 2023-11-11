/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:55:44 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/04 06:08:58 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "errno.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node {
	int				data;
	int				index;
	int				pos;
	struct s_node	*next;
}	t_node;

typedef struct s_move {
	int	step;
	int	route;
}	t_move;

//PS utility functions
void		check_param(char **argv);
void		sort_int_arr(int *tab, int size);
int			check_dubl(int *arr, int size);
void		set_pos(t_node **head, int *arr, int size);
char		**get_final_argv(int argc, char **argv);
int			get_final_size(char **final_argv);
int			ft_atoi_ps(char *str, char **final_argv, int *arr, int index);
int			space_check(char *str);
void		prepare_and_sort(t_node *a, t_node *b, char **final_argv, int size);
char		**get_arr(int argc, char **argv);
void		dirty_check(int argc, char **argv);

//list_utils
void		del_node(t_node **head);
t_node		*find_node(t_node **head, int data);
t_node		*ft_lstlast_ps(t_node *lst);
t_node		*ft_lstprelast_ps(t_node *lst);
int			ft_lstsize_ps(t_node **head);
void		push(t_node **head, int data, int index, int pos);
void		print_list(t_node **a);
int			find_max_node(t_node **head);
int			find_min_node(t_node **head);
void		reset_i(t_node **head);
void		free_list(t_node **head);

//operations
void		sa(t_node *a, int flag);
void		sb(t_node *b, int flag);
void		ss(t_node *a, t_node *b, int flag);
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		pb_sm(t_node **a, t_node **b);
void		ra(t_node **a, int flag);
void		rb(t_node **b, int flag);
void		rr(t_node **a, t_node **b, int flag);
void		rra(t_node **a, int flag);
void		rrb(t_node **b, int flag);
void		rrr(t_node **a, t_node **b, int flag);

//sorting
int			check_sort(t_node **head);
int			count_move(t_move *move, int size, int index);
void		sort_int_arr(int *tab, int size);
void		list_sort(t_node *a, t_node *b, int size);
void		sort_2(t_node **a);
void		sort_3(t_node **a);
void		sort_4(t_node **a, t_node **b, t_move *move);
void		sort_5(t_node **a, t_node **b, t_move *move);
void		sort_more(t_node **a, t_node **b, t_move *move, int *arr);
void		sort_more_1(t_node **a, t_node **b, t_move *move, int *arr);
void		move_to_top_min(t_move *move, t_node **head);
void		move_to_top_max(t_move *move, t_node **head);
void		move_to_top_cur(t_move *move, t_node **a, int pos);

//error & free handling
void		error(void);
void		error_2(char *str, char **final_argv);
void		free_argv(char **argv);
void		free_final_argv(char **final_argv);
void		free_final_argv_2(char **final_argv, int index);
void		free_complex(int *arr, char **final_argv);
void		free_complex_2(int *arr, char **final_argv, int index);
void		free_error_complex(int *arr, char **final_argv, int index);

#endif