/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_uns_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:16:45 by francema          #+#    #+#             */
/*   Updated: 2024/12/19 12:10:24 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	width_greatest(t_flags *flags, t_info *info, unsigned int arg, char *s)
{
	int		i;
	int		width;
	int		n_len;

	i = 0;
	width = flags->num;
	n_len = ft_uns_len(arg, 10, 0);
	if (flags->neg)
	{
		while (s[i])
			lputchar(s[i++], &(info->p_b));
		while(width > n_len++)
			lputchar(' ', &(info->p_b));
	}
	else
	{
		while(width > n_len++)
			lputchar(' ', &(info->p_b));
		while (s[i])
			lputchar(s[i++], &(info->p_b));
	}
}

static void	prec_greatest(t_info *info, t_flags *flags, unsigned int arg, char *s)
{
	int		prec;
	int		n_len;
	int		i;

	i = 0;
	prec = flags->dot;
	n_len = ft_uns_len(arg, 10, 0);
	while(prec > n_len++)
		lputchar('0', &(info->p_b));
	while(s[i] && i < prec)
		lputchar(s[i++], &(info->p_b));
}

static void	width_putin(t_flags *flags, t_info *info, unsigned int arg, char *s)
{
	int	n_len;
	int	i;

	i = 0;
	n_len = ft_uns_len(arg, 10, 0);
	if (flags->neg)
	{
		while(n_len + i++ < flags->dot)
			lputchar('0', &(info->p_b));
		i = 0;
		while (s[i])
			lputchar(s[i++], &(info->p_b));
		while(flags->num > n_len++)
			lputchar(' ', &(info->p_b));
	}
	else
	{
		while(flags->num > n_len + i++)
			lputchar(' ', &(info->p_b));
		while (n_len++ < flags->dot)
			lputchar('0', &(info->p_b));
		i = 0;
		while(s[i])
			lputchar(s[i++], &(info->p_b));
	}
}

void	put_prec_uns(t_flags *flags, t_info *info)
{
	char			*s;
	int				n_len;
	unsigned int	arg;

	s = NULL;
	arg = va_arg(*(info->args), unsigned int);
	n_len = ft_uns_len(arg, 10, 1);
	s = ft_utoa(arg, 1);
	if (flags->num <= n_len && flags->dot <= n_len)
		lputunsigned(arg, &(info->p_b));
	else if (flags->num > n_len && n_len > flags->dot)
		width_greatest(flags, info, arg, s);
	else if (flags->num < n_len && n_len < flags->dot)
		prec_greatest(info, flags, arg, s);
	else if (flags->num > n_len && n_len < flags->dot)
	{
		if (flags->dot >= flags->num)
		{
			while(flags->dot > n_len++)
				lputchar('0', &(info->p_b));
		}
		else if (flags->num > flags->dot)
			width_putin(flags, info, arg, s);
	}
	free(s);
}
