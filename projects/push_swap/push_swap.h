/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:52:49 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 18:13:55 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_node		*top_a;
	struct s_node		*top_b;
	int					size_a;
	int					size_b;
}						t_stack;

typedef struct s_node
{
	struct s_node	*next;
	int				num;
}					t_node;

void		ft_small_sort_a(t_stack *st_info, int n);
void		ft_small_sort_b(t_stack *st_info, int n);
void		ft_2sort_a(t_stack *st_info);
void		ft_2sort_b(t_stack *st_info);
void		ft_1_3_2_a(t_stack *st_info);
void		ft_2_3_1_a(t_stack *st_info);
void		ft_3_1_2_a(t_stack *st_info);
void		ft_3_2_1_a(t_stack *st_info);
void		ft_3sort_a(t_stack *st_info);
void		ft_2_1_3_b(t_stack *st_info);
void		ft_3_1_2_b(t_stack *st_info);
void		ft_1_3_2_b(t_stack *st_info);
void		ft_1_2_3_b(t_stack *st_info);
void		ft_3sort_b(t_stack *st_info);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_sign(char c);
int			ft_check_ovf(int nbr, int tmp);
int			ft_atoi(const char *str);
int			ft_num_len(char **argv, int size);
int			ft_maxint_check(int n, char *str);
int			*ft_put_num(char **argv, int size, int *num);
int			*ft_error_check(char **input, int size);
int			ft_input_sort_check(int *num, int len);
int			ft_init_a(t_stack *st_info, int num);
t_stack		*ft_stack_init(int *num, int len);
int			ft_split_len(char **split);
int			ft_split_check(char **argv, int size, int i);
int			ft_input_check(char **argv, int size);
int			ft_num_dupl_check(int *num, int len);
int			ft_get_word_cnt(char *str, char c);
void		ft_strput(char *dst, char *from, char *until);
void		ft_free(char **ret, int idx);
char		**ft_putwords(char *str, char c, char **ret);
char		**ft_split(char *str, char c);
void		ft_swap_a(t_stack *st_info);
void		ft_swap_b(t_stack *st_info);
void		ft_push_a(t_stack *st_info);
void		ft_push_b(t_stack *st_info);
void		ft_triple_push_a(t_stack *st_info);
void		ft_rotate_a(t_stack *st_info);
void		ft_rotate_b(t_stack *st_info);
void		ft_r_rotate_a(t_stack *st_info);
void		ft_r_rotate_b(t_stack *st_info);
int			ft_q_swap(int *arr, int left, int right, int pivot);
void		ft_q_sort(int *arr, int left, int right);
int			ft_pivot_a(t_stack *st_info, int n);
int			ft_pivot_b(t_stack *st_info, int n);
void		ft_rra_exec(t_stack *st_info, int ra);
void		ft_rrb_exec(t_stack *st_info, int rb);
int			ft_count_ra(t_stack *st_info, int ra);
int			ft_count_pb(t_stack *st_info, int pb);
int			ft_count_rb(t_stack *st_info, int rb);
int			ft_count_pa(t_stack *st_info, int pa);
void		ft_atob(t_stack *st_info, int n);
void		ft_btoa(t_stack *st_info, int n);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
#endif