/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/09 10:18:32 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_stdflags(char c)
{
	if (c != 's' && c != 'd' && c != 'u'
		&& c != 'x' && c != 'X' && c != 'p'
		&& c != 'c' && c != 'i' && c != '%')
		return (1);
	else
		return (0);
}

void	init_flags(char c, t_flags *flags, t_info *info, int *i)
{
	const char	*s;
	int		j;

	s = info->s;
	j = *i;
	if (c == '#')
		flags->sharp += 1;
	else if (c == '-')
		flags->neg += 1;
	else if (c == '+')
		flags->pos += 1;
	else if (c == '0')
		flags->zero += 1;
	else if (c >= '1' && c <= '9')
	{
		flags->num = ft_atoi(&s[j + 1]);
		info->i = ft_skip_num(s, j + 1);
	}
	else if (c == '.')
	{
		flags->dot = ft_atoi(&s[j + 1]);
		info->i = ft_skip_num(s, j + 1);
	}
	else if (c == ' ')
		flags->space += 1;
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

// void	init_flags(char c, t_flags *flags, t_info *info, int *i)
// {
// 	const char	*s;

// 	s = info->s;
// 	if (c == '#')
// 		flags->sharp += 1;
// 	else if (c == '-')
// 		flags->neg += 1;
// 	else if (c == '+')
// 		flags->pos += 1;
// 	else if (c == '0')
// 		flags->zero += 1;
// 	else if (c == ' ')
// 		flags->space += 1;
// 	else if (c == '.')
// 	{
// 		if (s[(*i) + 1] >= '1' && s[(*i) + 1] <= '9')
// 			flags->dot = ft_atoi(&s[(*i) + 1]);
// 		else
// 			flags->dot = 0;
// 	}
// 	else if (c >= '1' && c <= '9')
// 	{
// 		flags->num = ft_atoi(&s[(*i)]);
// 		(*i) = ft_skip_num(s, (*i));
// 	}
// }
