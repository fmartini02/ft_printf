/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:23:07 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 17:01:39 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_space(t_info *info, char c)
{
	lputchar(' ', &(info->p_b));
	if (c == 'd' || c == 'i')
		lputnbr(va_arg(*(info->args), int), &(info->p_b));
	else if (c == 'x' || c == 'X')
		lputexa(info, c);
	else if (c == 'c')
		lputchar(va_arg(*(info->args), int), &(info->p_b));
	else if (c == 's')
		lputstr(va_arg(*(info->args), char *), &(info->p_b));
	else if (c == 'u')
		lputunsigned(va_arg(*(info->args), unsigned int), &(info->p_b));
	else if (c == 'p')
		lputadrr(info);
}
