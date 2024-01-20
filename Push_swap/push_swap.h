/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:17:38 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/12 10:52:02 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}		t_list;

void	ft_swap(int *arr);
void	ft_swap_all(t_list *list, char c);
void	ft_push_a(t_list *list);
void	ft_push_b(t_list *list);
void	ft_rotate(int *arr, int len);
void	ft_rr_all(t_list *list, char c);
void	ft_rrr_all(t_list *list, char c);
void	ft_reverse_rotate(int *arr, int len);
void	ft_sort_all(t_list *list, int len);
void	ft_sort_two(t_list *list);
void	ft_sort_three(t_list *list);
void	ft_sort_four_five(t_list *list);
int		ft_max_num(t_list *list);
int		ft_max_digit(int max);
void	radix_sort(t_list *list);
void	ft_checker(char **str);
void	ft_check_args(int argc, char **argv);
void	ft_check_duplicate(t_list *list);
int		ft_check_sorted(t_list *list);
void	ft_error_message(void);
void	ft_create_stack_b(t_list *list, int count_elements);
int		*ft_create_stack_a(char **av, int count_elements);
void	ft_create_index(t_list *list);
void	ft_array_free(char **array);
void	ft_stack_free(t_list *list);
int		ft_count_element(char **av);
int		ft_atoint(char *str);

#endif
