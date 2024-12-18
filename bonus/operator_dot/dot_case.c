/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:05:01 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 17:43:40 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	width_greatest(t_flags *flags, t_info *info, int arg, char *s)
{
	int		i;
	int		width;
	int		n_len;

	i = 0;
	width = flags->num;
	n_len = ft_uns_len((unsigned long) arg, 10);
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

static void	prec_greatest(t_info *info, t_flags *flags, int arg, char *s)
{
	int		prec;
	int		n_len;
	int		i;

	i = 0;
	prec = flags->dot;
	n_len = ft_num_len(arg, 10);
	while(prec > n_len)
	{
		if (arg < 0)
		{
			lputchar('-', &(info->p_b));
			free(s);
			arg *= -1;
			s = ft_itoa(arg);
		}
		lputchar('0', &(info->p_b));
		n_len++;
	}
	while(s[i])
		lputchar(s[i++], &(info->p_b));
}

static void	width_putin(t_flags *flags, t_info *info, int arg, char *s)
{
	int	n_len;
	int	i;

	i = 0;
	n_len = ft_num_len(arg, 10);
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

void	put_prec_num(t_flags *flags, t_info *info)
{
	int		n_len;
	int		arg;
	char	*s;

	arg = va_arg(*(info->args), int);
	s = ft_itoa(arg);
	n_len = ft_num_len(arg, 10);
	if (flags->num <= n_len && flags->dot <= n_len)
			lputnbr(arg, &(info->p_b));
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

void	put_dot_case(t_flags *flags, t_info *info, char c)
{
	if (c == 'u')
		put_prec_uns(flags, info);
	else
		put_prec_num(flags, info);
}
