/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:10 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 17:44:53 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	zero_int_case(t_flags *flags, t_info *info)
{
	long int	n;
	int			i;
	char		*arg;

	n = va_arg(*(info->args), int);
	i = 0;
	if (n < 0)
	{
		lputchar('-', &(info->p_b));
		n *= -1;
		arg = ft_itoa(n);
	}
	else
	{
		if (flags->pos)
			lputchar('+', &(info->p_b));
		arg = ft_itoa(n);
	}
	while(i++ < flags->num)
		lputchar('0', &(info->p_b));
	lputstr(arg, &(info->p_b));
}

void	zero_uns_case(t_flags *flags, t_info *info)
{
	unsigned int	u;
	char			*arg;
	int				i;

	u = va_arg(*(info->args), unsigned int);
	arg = ft_itoa(u);
	i = 0;
	while(i++ < flags->num)
		lputchar('0', &(info->p_b));
	i = 0;
	lputstr(arg, &(info->p_b));
	free(arg);
}

void	zero_exa_case(t_flags *flags, t_info *info, char c)
{
	char			*base;
	unsigned int	n;
	int				len;
	char			*tmp;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	n = va_arg(*(info->args), int);
	len = ft_uns_len(n, 16);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return ;
	build_num(n, base, tmp);
	while(len++ < flags->num)
		lputchar('0', &(info->p_b));
	lputstr(tmp, &(info->p_b));
}

