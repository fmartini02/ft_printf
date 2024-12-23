/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_int_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:05:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/23 17:30:25 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	width_greatest(t_flags *flags, t_info *info, int arg)
{
	int		i;
	int		width;
	int		n_len;

	i = 0;
	width = flags->num;
	n_len = ft_num_len(arg, 10, 0);
	while(width > n_len++)
		lputchar(' ', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

static void	prec_greatest(t_info *info, t_flags *flags, int arg)
{
	int	prec;
	int	n_len;
	int	i;

	i = 0;
	prec = flags->dot;
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
	}
	n_len = ft_num_len(arg, 10);
	while(prec > n_len++)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

static void	width_putin(t_flags *flags, t_info *info, int arg)
{
	int	d_len;
	int	n_len;

	d_len = flags->dot;
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
		d_len++;
	if (d_len < flags->num)
	{
		while(d_len++ < flags->num)
			lputchar(' ', &(info->p_b));
	}
	if (arg < 0)
	{
		lputchar('-', &(info->p_b));
		arg *= -1;
		n_len = ft_num_len(arg, 10);
	}
	while(n_len++ < flags->dot)
		lputchar('0', &(info->p_b));
	lputnbr(arg, &(info->p_b));
}

void	put_prec_num(t_flags *flags, t_info *info)
{
	int		n_len;
	int		arg;

	arg = va_arg(*(info->args), int);
	n_len = ft_num_len(arg, 10);
	if (arg < 0)
		n_len--;
	if (flags->num <= n_len && flags->dot <= n_len)
		lputnbr(arg, &(info->p_b));//n_len greater than both
	else if (flags->num > n_len && n_len > flags->dot)
		width_greatest(flags, info, arg);//width greater than both
	else if (flags->num < n_len && n_len < flags->dot)
		prec_greatest(info, flags, arg);//prec greater than both
	else if (n_len < flags->num && n_len < flags->dot)
		width_putin(flags, info, arg);//n_len less than prec and less than width
}
