/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:48:38 by francema          #+#    #+#             */
/*   Updated: 2024/12/12 16:55:23 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	magic_ptr(void *ptr, int width, t_info *info, char c, t_flags *flags)
{
	unsigned long	nu;
	int				nu_len;

	nu = (unsigned long)ptr;
	nu_len = 0;
	if (!ptr && c == 'p')
		nu_len = 5;
	else if (!ptr && c == 's')
		nu_len = 0;
	else
	{
		if (c == 'p')
			nu_len = ft_num_len(nu, 16) + 2;
		else if (c == 's')
			nu_len = ft_strlen((const char *)ptr);
	}
	print_width(width, nu_len, info, flags);
	if (!ptr && c == 'p')
		lputstr("(nil)", &(info->p_b));
	else
			ptr_case(ptr, info, c);
}

void	magic_uns(unsigned int uns, char c, int width, t_info *info, t_flags *flags)
{
	int		nu_len;
	int		i;
	char	*tmp;

	nu_len = 0;
	if (c == 'x' || c == 'X')
		nu_len = ft_num_len(uns, 16);
	else if (c == 'u')
		nu_len = ft_num_len(uns, 10);
	i = 0;
	print_width(width, nu_len, info, flags);
	tmp = malloc(sizeof(char) * (nu_len + 1));
	if (!tmp)
		return ;
	if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			build_num(uns, "0123456789abcdef", tmp);
		else
			build_num(uns, "0123456789ABCDEF", tmp);
	}
	else if (c == 'u')
		build_num(uns, "0123456789", tmp);
	lputstr(tmp, &(info->p_b));
	free(tmp);
}

void	magic_char(int n, int width, t_info *info, t_flags *flags)
{
	int				len;
	unsigned int	uns;

	len = 1;
	uns = n;
	print_width(width, len, info, flags);
	lputchar(uns, &(info->p_b));
}

void	magic_num(char *arg, int width, t_info *info, t_flags *flags)
{
	int	arg_len;

	if (!arg)
		return ;
	arg_len = ft_strlen((const char*)arg);
	print_width(width, arg_len, info, flags);
	lputstr(arg, &(info->p_b));
}
