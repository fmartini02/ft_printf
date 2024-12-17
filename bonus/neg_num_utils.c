/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_num_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:08:55 by francema          #+#    #+#             */
/*   Updated: 2024/12/17 16:45:03 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	neg_magic_ptr(void *ptr, int width, t_info *info, char c, t_flags *flags)
{
	unsigned long	nu;
	int				nu_len;

	nu = (unsigned long)ptr;
	nu_len = 0;
	if (!ptr && c == 'p')
		nu_len = 5;
	else
	{
		if (c == 'p')
			nu_len = ft_uns_len(nu, 16) + 2;
		else if (c == 's')
			nu_len = ft_strlen((const char *)ptr);
	}
	if (!ptr && c == 'p')
		lputstr("(nil)", &(info->p_b));
	else
			ptr_case(ptr, info, c);
	print_width(width, nu_len, info, flags);
}

void	neg_magic_uns(unsigned int uns, char c, int width, t_info *info, t_flags *flags)
{
	int		nu_len;
	int		i;
	char	*tmp;

	nu_len = 0;
	if (c == 'x' || c == 'X')
		nu_len = ft_uns_len(uns, 16);
	else if (c == 'u')
		nu_len = ft_uns_len(uns, 10);
	i = 0;
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
	print_width(width, nu_len, info, flags);
	free(tmp);
}

void	neg_magic_char(int n, int width, t_info *info, t_flags *flags)
{
	int				len;
	unsigned int	u;

	len = 1;
	u = n;
	lputchar(u, &(info->p_b));
	print_width(width, len, info, flags);
}

void	neg_magic_num(char *arg, int width, t_info *info, t_flags *flags)
{
	int	arg_len;

	arg_len = ft_strlen((const char*)arg);
	lputstr(arg, &(info->p_b));
	print_width(width, arg_len, info, flags);
}
