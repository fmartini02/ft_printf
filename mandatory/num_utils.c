/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:08:55 by francema          #+#    #+#             */
/*   Updated: 2024/12/10 17:12:24 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	magic_ptr(void *ptr, int width, t_info *info)
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
	print_width(width, nu_len, info);
	if (!ptr)
		lputstr("nil", &(info->p_b));
	else
		ptr_case(nu, info);
}

void	magic_uns(unsigned int uns, char c, int width, t_info *info)
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
	print_width(width, nu_len, info);
	lputstr(tmp, &(info->p_b));
	free(tmp);
}

void	magic_char(int n, int width, t_info *info)
{
	int	len;

	len = 1;
	print_width(width, len, info);
	lputchar(n, &(info->p_b));
}

void	magic_num(char *arg, int width, t_info *info)
{
	int	arg_len;

	arg_len = ft_strlen((const char *)arg);
	print_width(width, arg_len, info);
	lputstr(arg, &(info->p_b));
}
