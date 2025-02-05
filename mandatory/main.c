/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:47:53 by francema          #+#    #+#             */
/*   Updated: 2025/01/07 18:27:28 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	expand_flags(t_info *info)
{
	const char	*str;
	int			j;

	str = info->s;
	j = info->i;
	if (check_stdflags(str[j]))
		return ;
	else if (str[j] == 's')
		lputstr(va_arg(*(info->args), char *), &(info->p_b));
	else if (str[j] == 'c')
		lputchar(va_arg(*(info->args), int), &(info->p_b));
	else if (str[j] == 'd' || str[j] == 'i')
		lputnbr(va_arg(*(info->args), int), &(info->p_b));
	else if (str[j] == 'u')
		lputunsigned(va_arg(*(info->args), unsigned), &(info->p_b));
	else if (str[j] == 'x' || str[j] == 'X')
		lputexa(info, str[j]);
	else if (str[j] == 'p')
		lputadrr(info);
	else if (str[j] == '%')
		lputchar('%', &(info->p_b));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_info	*info;
	int		p_b;

	va_start(args, str);
	info = malloc(sizeof(t_info));
	if (!info || !str)
		return (-1);
	init_info(info, str, &args);
	while (info->s[info->i])
	{
		if (info->s[info->i] == '%')
		{
			(info->i)++;
			expand_flags(info);
		}
		else
			lputchar(info->s[info->i], &(info->p_b));
		(info->i)++;
	}
	p_b = info->p_b;
	free(info);
	va_end(args);
	return (p_b);
}
