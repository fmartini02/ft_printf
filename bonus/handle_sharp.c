/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:44 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 17:09:40 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


void	handle_sharp(t_info *info, char c, t_flags *flags)
{
	if (c == 'x')
		lputstr("0x", &(info->p_b));
	else
		lputstr("0X", &(info->p_b));
	lputexa(info, c);
	flags->done = 1;
}


