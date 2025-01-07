/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_int_neg_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:05 by francema          #+#    #+#             */
/*   Updated: 2025/01/07 17:09:41 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	neg_width_greatest(t_flags *flags, t_info *info, int arg)
{
	int		i;
	int		width;
	int		n_len;

	i = 0;
	width = flags->num;
	n_len = ft_num_len(arg, 10);
	if (arg == 0 && flags->dot == 0)
		return ;
	lputnbr(arg, &(info->p_b));
	while (width > n_len++)
		lputchar(' ', &(info->p_b));
}

static void	neg_prec_greatest(t_info *info, t_flags *flags, int arg)
{
	int		prec;
	int		n_len;
	int		i;

	i = 0;
	prec = flags->dot;
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
	}
	n_len = ft_num_len(arg, 10);
	while (prec > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

static void	neg_width_putin(t_flags *flags, t_info *info, int arg)
{
	int	n_len;
	int	d_len;
	int	flag;

	n_len = ft_num_len(arg, 10);
	d_len = flags->dot;
	flag = 0;
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
		n_len--;
		flag = 1;
	}
	while (n_len++ < d_len)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
	if (flag)
		d_len++;
	while (flags->num > d_len++)
		lputchar(' ', &(info->p_b));
}

void	put_prec_num_neg(t_flags *flags, t_info *info)
{
	int	n_len;
	int	arg;

	arg = va_arg(*(info->args), int);
	dot_edge_case(flags, info, arg, 'd');
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
		n_len--;
	if (flags->num <= n_len && flags->dot <= n_len)
	{
		if (arg == 0 && flags->dot == 0)
			return ;
		lputnbr(arg, &(info->p_b));
	}
	else if (flags->num > n_len && n_len > flags->dot)
		neg_width_greatest(flags, info, arg);
	else if (flags->num <= n_len && n_len < flags->dot)
		neg_prec_greatest(info, flags, arg);
	else if (n_len < flags->num && n_len < flags->dot)
		neg_width_putin(flags, info, arg);
}
