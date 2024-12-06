/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:44 by francema          #+#    #+#             */
/*   Updated: 2024/12/03 18:04:53 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*handle_zero(t_flags *flags, t_info *info, char c)
{
	char	*ret;
	int		len;

	len = find_len(flags, info, c);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (c == 'c')
		ret = char_case(flags, info, ret);
	else if (c == 's')
		ret = str_case(flags, info, ret);
	else if (c == 'd' || c == 'i')
		ret = int_case(flags, info, ret);
	else if (c == 'u')
		ret = uns_case(flags, info, ret);
	lputstr(ret, &(info->p_b));
}

void	*handle_space(t_flags *flags, t_info *info, char c)
{
	char	*ret;
	int		len;

	len = find_len(flags, info, c);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (c == 'i' || c == 'd')
	{
		set_ret(flags, info, ret, c);
		lputchar(' ', &(info->p_b));
	}
	else
		set_ret(flags, info, ret, c);
}

void	handle_sharp(t_flags *flags, t_info *info, char c)
{
	if (c == 'X')
	{
		lputstr("0X", &(info->p_b));
		lputexa(info, c);
	}
	else
	{
		lputstr("0x", &(info->p_b));
		lputexa(info, c);
	}
}

void	handle_dot(t_flags *flags, t_info *info, char c)
{
	int		len;
	int		arg;
	char	ret;

	len = find_len(flags, info, c);
	ret = malloc(sizeof(char) * (len + 1));
	if (c == 's' || c == 'c' || c == 'p')
	{
		if (c == 'c')
			lputchar(va_arg(*(info->args), int), &(info->p_b));
		else if (c == 's')
			lputstr(va_arg(*(info->args), char *), &(info->p_b));
		else if (c == 'p')
			lputadrr(info);
	}
	else
		put_precision(ret, flags, info, c);
}
