/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 16:22:35 by francema         ###   ########.fr       */
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

int	init_flags(char c, t_flags *flags, t_info *info, int *i)
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
		flags->num = ft_atoi(&s[j]);
		return (ft_skip_num(s, j));
	}
	else if (c == '.')
	{
		flags->dot = ft_atoi(&s[j + 1]);
		return (ft_skip_num(s, j + 1));
	}
	else if (c == ' ')
		flags->space += 1;
	return (j + 1);
}

void	ptr_case(void *ptr, t_info *info)
{
	char			*tmp;
	int				nu_len;
	unsigned long	nu;

	nu = (unsigned long)ptr;
	nu_len = ft_uns_len(nu, 16);
	lputstr("0x", &(info->p_b));
	tmp = malloc(sizeof(char) * (nu_len + 1));
	if (!tmp)
		return;
	build_num(nu, "0123456789abcdef", tmp);
	lputstr(tmp, &(info->p_b));
	free(tmp);
}