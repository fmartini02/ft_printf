/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_case_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:41:10 by francema          #+#    #+#             */
/*   Updated: 2024/12/06 16:15:43 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	char_case(t_flags *flags, t_info *info)
{
	int	n;
	int	i;

	n = va_arg(*(info->args), int);
	i = 0;
	if (flags->neg)
	{
		lputchar(n, &(info->p_b));
		while (i++ < flags->num)
			lputchar(' ', &(info->p_b));
	}
	else
	{
		while (i < flags->num - 1)
			lputchar(' ', &(info->p_b));
		lputchar(n, &(info->p_b));
	}
}

void	str_case(t_flags *flags, t_info *info)
{
	char	*arg;
	int		i;

	i = 0;
	arg = va_arg(*(info->args), char *);
	if (flags->neg)
	{
		while(arg[i])
			lputchar(arg[i++], &(info->p_b));
		while (i++ < flags->num)
			lputchar(' ', &(info->p_b));
	}
	else
	{
		while(i++ < (flags->num - (int)ft_strlen(arg)))
			lputchar(' ', &(info->p_b));
		while(*arg)
			lputchar((*arg)++, &(info->p_b));
	}
}

void	int_case(t_flags *flags, t_info *info)
{
	int		n;
	int		i;
	char	*arg;

	n = va_arg(*(info->args), int);
	arg = ft_itoa(n);
	i = 0;
	if (flags->neg)
		int_neg_case(flags, info, arg);
	else
	{
		while (i++ < (flags->num  - (int)ft_strlen(arg)))
			lputchar('0', &(info->p_b));
		while (*arg)
			lputchar((*arg)++, &(info->p_b));
		if (flags->pos)
			int_pos_case(info, arg);
	}
	free(arg);
}

void	uns_case(t_flags *flags, t_info *info)
{
	unsigned int	u;
	char			*arg;
	int				i;

	u = va_arg(*(info->args), unsigned int);
	arg = ft_itoa((long long int)u);
	i = 0;
	if (flags->neg)
	{
		while(arg[i])
			lputchar(arg[i++], &(info->p_b));
		while(i++ < flags->num)
			lputchar('0', &(info->p_b));
	}
	else
	{
		while(i < (flags->num - ft_num_len(u, 10)))
			lputchar('0', &(info->p_b));
		while(*arg)
			lputchar((*arg)++, &(info->p_b));
	}
	free(arg);
}
