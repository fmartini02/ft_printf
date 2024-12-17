/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:06:58 by francema          #+#    #+#             */
/*   Updated: 2024/12/17 16:35:50 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_width(int width, int len, t_info *info, t_flags *flags)
{
	while ((width - len) > 0)
	{
		if (flags->zero)
			lputchar('0', &(info->p_b));
		else
			lputchar(' ', &(info->p_b));
		len++;
	}
}

void	ptr_case(void *ptr, t_info *info, char c)
{
	char			*tmp;
	int				nu_len;
	unsigned long	nu;

	nu = (unsigned long)ptr;
	if (!ptr && c == 'p')
		nu_len = 3;
	else
	{
		if (c == 'p')
			nu_len = ft_uns_len(nu, 16) + 2;
		else if (c == 's')
			nu_len = ft_strlen((const char *)ptr);
	}
	if (c == 'p')
	{
		lputstr("0x", &(info->p_b));
		tmp = malloc(sizeof(char) * (nu_len + 1));
		if (!tmp)
			return;
		build_num(nu, "0123456789abcdef", tmp);
		lputstr(tmp, &(info->p_b));
		free(tmp);
	}
	else if (c == 's')
		lputstr((char *)ptr, &(info->p_b));
}

void	neg_case(int width, t_info *info, char c, t_flags *flags)
{
	int				n;
	char			*arg;
	unsigned int	u;

	n = -1;
	arg = NULL;
	u = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'x' || c == 'X')
		n = va_arg(*(info->args), int);
	if (c == 'X' || c == 'x')
		u = n;
	if (c == 'c')
		neg_magic_char(n, width, info, flags);
	else if (c == 'd' || c == 'i')
		neg_magic_num(ft_itoa(n), width, info, flags);
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		if (c == 'x' || c == 'X')
			neg_magic_uns(u, c, width, info, flags);
		else
			neg_magic_uns(va_arg(*(info->args), unsigned int), c, width, info, flags);
	}
	else if (c == 'p' || c == 's')
	{
		if (c == 'p')
			neg_magic_ptr(va_arg(*(info->args), void*), width, info, c, flags);
		else
			neg_magic_ptr(va_arg(*(info->args), char*), width, info, c, flags);
	}
}

void	handle_num(int width, t_info *info, char c, t_flags *flags)
{
	int				n;
	char			*arg;
	unsigned int	u;

	n = -1;
	arg = NULL;
	u = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == 'x' || c == 'X')
		n = va_arg(*(info->args), int);
	if (c == 'X' || c == 'x')
		u = n;
	if (c == 'c')
		magic_char(n, width, info, flags);
	else if (c == 'd' || c == 'i')
		magic_num(ft_itoa(n), width, info, flags);
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		if (c == 'x' || c == 'X')
			magic_uns(u, c, width, info, flags);
		else
			magic_uns(va_arg(*(info->args), unsigned int), c, width, info, flags);
	}
	else if (c == 'p' || c == 's')
	{
		if (c == 'p')
			magic_ptr(va_arg(*(info->args), void*), width, info, c, flags);
		else
			magic_ptr(va_arg(*(info->args), char*), width, info, c, flags);
	}
}
