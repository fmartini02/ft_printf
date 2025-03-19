/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:07:37 by francema          #+#    #+#             */
/*   Updated: 2025/03/13 15:12:51 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	edge_case_utils(t_flags *flags, t_info *info,
							unsigned long int arg)
{
	int	dot_len;
	int	arg_int;
	int	n_len;
	int	ret;

	dot_len = flags->dot;
	arg_int = (int)arg;
	n_len = ft_num_len(arg_int, 10);
	ret = 0;
	if (dot_len == 0 && arg_int == 0)
	{
		while (flags->num-- > 0)
			lputchar(' ', &(info->p_b));
		ret = 1;
	}
	return (ret);
}

int	dot_edge_case(t_flags *flags, t_info *info,
						unsigned long int arg, char c)
{
	int				n_prec;
	unsigned int	arg_uns;

	n_prec = flags->dot;
	if (edge_case_utils(flags, info, arg))
		return (1);
	if (c == 'u' || c == 'x' || c == 'X')
	{
		arg_uns = (unsigned int)arg;
		if (n_prec == 0 && arg_uns == 0)
		{
			print_width(flags->num, 0, info, flags);
			return (1);
		}
	}
	else if (c == 'p')
	{
		if (n_prec == 0 && arg == 0)
		{
			print_width(flags->num, 0, info, flags);
			return (1);
		}
	}
	return (0);
}

void	build_exa(char c, char *s, unsigned int arg)
{
	if (c == 'x')
		build_num(arg, "0123456789abcdef", s, 0);
	else
		build_num(arg, "0123456789ABCDEF", s, 0);
}

void	exa_dot_width_greatest(t_flags *flags, t_info *info, char *s)
{
	int	n_prec;

	n_prec = flags->dot;
	if (n_prec > (int)ft_strlen(s))
	{
		while (flags->num-- > n_prec)
			lputchar(' ', &(info->p_b));
	}
	else
	{
		while (flags->num-- > (int)ft_strlen(s))
			lputchar(' ', &(info->p_b));
	}
}
