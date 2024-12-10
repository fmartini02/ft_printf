/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/09 11:50:10 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_stdflags(char c)
{
	if (c != 's' && c != 'd' && c != 'u'
		&& c != 'x' && c != 'X' && c != 'p'
		&& c != 'c' && c != 'i' && c != '%')
		return (1);
	else
		return (0);
}

void	int_neg_case(t_flags *flags, t_info *info, char *arg)
{
	int		i;

	i = 0;
	if (flags->pos)
		int_pos_case(info, arg);
	while(arg[i])
		lputchar(arg[i++], &(info->p_b));
	while(i < flags->num)
		lputchar(' ', &(info->p_b));
}

void	int_pos_case(t_info *info, char *arg)
{
	if (arg[0] == '-')
		lputchar('-', &(info->p_b));
	else if (arg[0] == '+')
		lputchar('+', &(info->p_b));
}
