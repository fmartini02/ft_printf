/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:48:38 by francema          #+#    #+#             */
/*   Updated: 2024/12/10 17:11:04 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_case(unsigned long nu, t_info *info)
{
	char	*tmp;
	int		nu_len;

	nu_len = ft_num_len(nu, 16);
	tmp = malloc(sizeof(char) * (nu_len + 1));
	if (!tmp)
		return;
	lputstr("0x", &(info->p_b));
	build_num(nu, "0123456789abcdef", tmp);
	lputstr(tmp, &(info->p_b));
	free(tmp);
}

void	neg_magic_ptr(void *ptr, int width, t_info *info)
{
	unsigned long	nu;
	int				nu_len;
	int				i;

	nu = (unsigned long)ptr;
	i = 0;
	if (!ptr)
		nu_len = 3;
	else
		nu_len = ft_num_len(nu, 16) + 2;
	if (!ptr)
		lputstr("nil", &(info->p_b));
	else
		ptr_case(nu, info);
	print_width(width, nu_len, info);
}

void	neg_magic_uns(unsigned int uns, char c, int width, t_info *info)
{
	int		nu_len;
	int		i;
	char	*tmp;

	nu_len = 0;
	i = 0;
	if (c == 'x' || c == 'X')
		nu_len = ft_num_len(uns, 16);
	else if (c == 'u')
		nu_len = ft_num_len(uns, 10);
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
	print_width(width, nu_len, info);
	free(tmp);
}

void	neg_magic_char(int n, int width, t_info *info)
{
	int	len;

	len = 1;
	lputchar(n, &(info->p_b));
	print_width(width, len, info);
}

void	neg_magic_num(char *arg, int width, t_info *info)
{
	int	arg_len;

	arg_len = ft_strlen((const char*)arg);
	lputstr(arg, &(info->p_b));
	print_width(width, arg_len, info);
}
