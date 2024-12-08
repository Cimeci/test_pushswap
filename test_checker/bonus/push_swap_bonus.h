/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:53:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 22:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../mandatory/push_swap.h"

///////////////////////
//      struct       //
///////////////////////

typedef struct s_moves
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;
	char	*rrr;
}			t_moves;

/////////////////////////////
//        ft_tools.c       //
/////////////////////////////

long	*sort_long_tab(long *tab, int size);
int		ft_strcmp(const char *s1, const char *s2);

/////////////////////////////
//       ft_checker.c      //
/////////////////////////////

void	ft_checker(t_stacks *stacks);

/////////////////////////////
//    ft_modification.c    //
/////////////////////////////

void	apply_modification(char *line, t_stacks *stacks)

/////////////////////////////
//    ft_moves_a_bonus.c   //
/////////////////////////////

void	sa_bonus(t_stacks *stacks);
void	ra_bonus(t_stacks *stacks);
void	rra_bonus(t_stacks *stacks);
void	pa_bonus(t_stacks *stacks);

/////////////////////////////
//   ft_moves_b_bonus.c    //
/////////////////////////////

void	sb_bonus(t_stacks *stacks);
void	rb_bonus(t_stacks *stacks);
void	rrb_bonus(t_stacks *stacks);
void	pb_bonus(t_stacks *stacks);

/////////////////////////////
// ft_moves_double_bonus.c //
/////////////////////////////

void	rr_bonus(t_stacks *stacks);
void	rrr_bonus(t_stacks *stacks);
void	ss_bonus(t_stacks *stacks);

#endif