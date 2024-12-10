/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:06:58 by francema          #+#    #+#             */
/*   Updated: 2024/12/10 19:03:19 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_width(int width, int len, t_info *info)
{
	while ((width - len) > 0)
	{
		lputchar(' ', &(info->p_b));
		len++;
	}
}

void	neg_case(int width, t_info *info, char c)
{
	int				n;
	char			*arg;
	unsigned int	u;

	n = -1;
	arg = NULL;
	u = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'x' || c == 'X')
		n = va_arg(*(info->args), int);
	if (c == 'd' || c == 'i')
		arg = ft_itoa((long long)c);
	if (c == 'X' || c == 'x')
		u = n;
	else if (c == 's')
		arg = va_arg(*(info->args), char *);
	else if (c == 'u')
		u = va_arg(*(info->args), unsigned int);
	else if (c == 'p')
		arg = va_arg(*(info->args), void*);
	if (arg && !u && !n)
		neg_magic_ptr(arg, width, info);
	else if (u)
		neg_magic_uns(u, c, width, info);
	else if (n && arg)
		neg_magic_num(arg, width, info);
	else if (n >= 0)
		neg_magic_char(n, width, info);
}

void	handle_num(int width, t_info *info, char c)
{
	int				n;
	char			*arg;
	unsigned int	u;

	n = -1;
	arg = NULL;
	u = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'x' || c == 'X')
		n = va_arg(*(info->args), int);
	if (c == 'd' || c == 'i')
		arg = ft_itoa((long long)c);
	if (c == 'X' || c == 'x')
		u = n;
	else if (c == 's')
		arg = va_arg(*(info->args), char *);
	else if (c == 'u')
		u = va_arg(*(info->args), unsigned int);
	else if (c == 'p')
		arg = va_arg(*(info->args), void*);
	if (arg && !u && !n)
		magic_ptr(arg, width, info);
	else if (u)
		magic_uns(u, c, width, info);
	else if (n && arg)
		magic_num(arg, width, info);
	else if (n >= 0)
		magic_char(n, width, info);
}
