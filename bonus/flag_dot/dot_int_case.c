/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_int_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:05:01 by francema          #+#    #+#             */
/*   Updated: 2025/03/13 17:37:01 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	w_n_d(t_flags *flags, t_info *info, long int arg)
{
	int	d_len;
	int	w_len;
	int	n_len;

	d_len = flags->dot;
	w_len = flags->num;
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
		n_len++;
	while (w_len > n_len++)
		lputchar(' ', &(info->p_b));
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
	}
	lputnbr(arg, &(info->p_b));
}

static void	w_d_n(t_flags *flags, t_info *info, int arg)
{
	int	d_len;
	int	w_len;
	int	n_len;
	int	tmp;

	d_len = flags->dot;
	w_len = flags->num;
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
		d_len++;
	tmp = d_len;
	while (w_len > tmp++)
		lputchar(' ', &(info->p_b));
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
		d_len--;
	}
	while (d_len > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

static void	d_greatest(t_info *info, t_flags *flags, long int arg)
{
	int	prec_len;
	int	n_len;
	int	i;

	i = 0;
	prec_len = flags->dot;
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
	}
	n_len = ft_num_len(arg, 10);
	while (prec_len > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

void	dot_int_case(t_flags *flags, t_info *info)
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
		w_n_d(flags, info, arg);
	else if (w_len > d_len && n_len < d_len)
		w_d_n(flags, info, arg);
	else if (n_len >= d_len && d_len >= w_len)
		lputnbr(arg, &(info->p_b));
	else if (n_len >= w_len && w_len >= d_len)
		lputnbr(arg, &(info->p_b));
	else if (d_len >= w_len && w_len >= n_len)
		d_greatest(info, flags, arg);
	else if (d_len > n_len && n_len >= w_len)
		d_greatest(info, flags, arg);
}
