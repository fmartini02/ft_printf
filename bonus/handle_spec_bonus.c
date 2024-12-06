/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:44 by francema          #+#    #+#             */
/*   Updated: 2024/12/06 16:15:24 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_zero(t_flags *flags, t_info *info, char c)
{
	if (c == 'c')
		char_case(flags, info);
	else if (c == 's')
		str_case(flags, info);
	else if (c == 'd' || c == 'i')
		int_case(flags, info);
	else if (c == 'u')
		uns_case(flags, info);
}

void	handle_sharp(t_info *info, char c)
{
	lputstr("0x", &(info->p_b));
	if (c == 'X')
		lputexa(info, c);
	else
		lputexa(info, c);
}

void	handle_dot(t_flags *flags, t_info *info, char c)
{
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
		put_precision(flags, info, c);
}
