/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madatory_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:00:14 by francema          #+#    #+#             */
/*   Updated: 2024/12/06 11:52:03 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_num(unsigned long int n, char *base, char *buf)
{
	int	len;
	int	l_base;

	l_base = ft_strlen(base);
	len = ft_num_len(n, l_base);
	buf[len--] = '\0';
	if (n == 0)
		buf[len--] = base[0];
	while (n > 0)
	{
		buf[len--] = base[n % l_base];
		n /= ft_strlen(base);
	}
}

void	lputunsigned(t_info *info)
{
	char	*s;

	info->u_tmp = va_arg(*(info->args), unsigned int);
	s = malloc(sizeof(char) * (ft_num_len(info->u_tmp, 10) + 1));
	if (!s)
		return ;
	build_num(info->u_tmp, "0123456789", s);
	lputstr(s, &(info->p_b));
	free(s);
}

void	lputexa(t_info *info, char c)
{
	char			*base;
	char			*buf;

	base = "0123456789abcdef";
	info->u_tmp = va_arg(*(info->args), int);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == '\0')
		lputstr("0x", &(info->p_b));
	buf = malloc(sizeof(char) * (ft_num_len(info->u_tmp, 16) + 1));
	if (!buf)
		return ;
	build_num(info->u_tmp, base, buf);
	lputstr(buf, &(info->p_b));
	free(buf);
}

void	lputadrr(t_info *info)
{
	void	*p;
	char	*base;
	char	*buf;

	p = va_arg(*(info->args), void *);
	if (!p)
	{
		lputstr("(nil)", &(info->p_b));
		return ;
	}
	base = "0123456789abcdef";
	info->p_tmp = (unsigned long int) p;
	info->u_tmp = 0;
	buf = malloc(sizeof(char) * (ft_num_len(info->p_tmp, 16) + 1));
	if (!buf)
		return ;
	lputstr("0x", &(info->p_b));
	build_num(info->p_tmp, base, buf);
	lputstr(buf, &(info->p_b));
	free(buf);
}

/*
if (n >= 0)
	nbr = n;
else
	nbr = UINT_MAX + n + 1;

COMPLEMENTO A DUE
*/
