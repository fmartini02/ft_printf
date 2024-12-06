/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:23:07 by francema          #+#    #+#             */
/*   Updated: 2024/12/06 16:15:18 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_space(t_info *info, char c)
{
	lputchar(' ', &(info->p_b));
	if (c == 'd' || c == 'i')
		lputnbr(info, va_arg(*(info->args), int));
	else if (c == 'x' || c == 'X')
		lputexa(info, c);
	else if (c == 'c')
		lputchar(va_arg(*(info->args), int), &(info->p_b));
	else if (c == 's')
		lputstr(va_arg(*(info->args), char *), &(info->p_b));
}
