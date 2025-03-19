/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_int_neg_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:05 by francema          #+#    #+#             */
/*   Updated: 2025/03/13 17:36:27 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	neg_w_n_d(t_flags *flags, t_info *info, int arg)
{
	int	d_len;
	int	w_len;
	int	n_len;

	d_len = flags->dot;
	w_len = flags->num;
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
		n_len++;
	}
	lputnbr(arg, &(info->p_b));
	while (w_len > n_len++)
		lputchar(' ', &(info->p_b));
}

static void	neg_w_d_n(t_flags *flags, t_info *info, int arg)
{
	int	d_len;
	int	w_len;
	int	n_len;
	int	tmp;

	d_len = flags->dot;
	w_len = flags->num;
	n_len = ft_num_len(arg, 10);
	tmp = d_len;
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		tmp = d_len + 1;
		arg *= -1;
	}
	while (d_len > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
	while (w_len > tmp++)
		lputchar(' ', &(info->p_b));
}

static void	neg_d_greatest(t_flags *flags, t_info *info, long int arg)
{
	int	d_len;
	int	w_len;
	int	n_len;

	d_len = flags->dot;
	w_len = flags->num;
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
	}
	while (d_len > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

void	neg_dot_int_case(t_flags *flags, t_info *info)
{
	int	n_len;
	int	arg;
	int	d_len;
	int	w_len;

	arg = va_arg(*(info->args), int);
	if (dot_edge_case(flags, info, arg, 'd'))
		return ;
	n_len = ft_num_len(arg, 10);
	d_len = flags->dot;
	w_len = flags->num;
	if (w_len > n_len && n_len >= d_len)
		neg_w_n_d(flags, info, arg);
	else if (w_len > d_len && n_len < d_len)
		neg_w_d_n(flags, info, arg);
	else if (n_len >= d_len && d_len >= w_len)
		lputnbr(arg, &(info->p_b));
	else if (n_len >= w_len && w_len >= d_len)
		lputnbr(arg, &(info->p_b));
	else if (d_len >= w_len && w_len >= n_len)
		neg_d_greatest(flags, info, arg);
	else if (d_len > n_len && n_len >= w_len)
		neg_d_greatest(flags, info, arg);
}
