/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/03 16:13:53 by francema         ###   ########.fr       */
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

void	init_flags(char c, t_flags *flags, t_info *info)
{
	char	*s;
	int		i;

	s = info->s;
	i = info->i;
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
		flags->num = ft_atoi(&s[i + 1]);
		info->i = ft_skip_num(s, i + 1);
	}
	else if (c == '.')
	{
		flags->dot = ft_atoi(&s[i + 1]);
		info->i = ft_skip_num(s, i + 1);
	}
	else if (c == ' ')
		flags->space += 1;
}

void	int_case_utils(t_flags *flags, t_info *info, char *ret, char *arg)
{
	int		i;
	int		sign;
	char	*arg;

	i = 0;
	sign = 0;
	if (flags->pos)
	{
		if (sign == -1)
			ret[i++] == '-';
		else
			ret[i++] == '+';
	}
	i -= 1;
	while(arg[++i])
		ret[i] = arg[i];
	while(i < flags->num)
		ret[i++] = '0';
	ret[i] = '\0';
}

void	int_case_utils2(t_flags *flags, t_info *info, char *ret, char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		ret[i] = arg[i];
	else
		ret[i] = '+';
	i++;
	while (i < (flags->num  - ft_strlen(arg)))
	{
		ret[i] = arg[i];
		i++;
	}
	(*arg)++;
	while(*arg)
		ret[i++] = (*arg)++;
}
