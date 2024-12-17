/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:41:10 by francema          #+#    #+#             */
/*   Updated: 2024/12/17 16:37:18 by francema         ###   ########.fr       */
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
	long int	n;
	int		i;
	int		j;
	char	*arg;


	n = va_arg(*(info->args), int);
	i = 0;
	if (n < 0)
	{
		if (n != INT_MIN)
			arg = ft_itoa(n * -1);
		else
			arg = ft_strdup("2147483648");
		n *= -1;
		lputchar('-', &(info->p_b));
		i += 1;
	}
	else
		arg = ft_itoa(n);
	j = 0;
	if (flags->neg)
		int_neg_case(flags, info, arg);
	else
	{
		while (i++ < (flags->num  - (int)ft_strlen(arg)))
			lputchar('0', &(info->p_b));
		while (arg[j])
			lputchar(arg[j++], &(info->p_b));
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
	int				j;

	u = va_arg(*(info->args), unsigned int);
	arg = ft_itoa(u);
	i = 0;
	j = 0;
	if (flags->neg)
	{
		while(arg[i])
			lputchar(arg[i++], &(info->p_b));
		while(i++ < flags->num)
			lputchar('0', &(info->p_b));
	}
	else
	{
		while(i++ < (flags->num - ft_uns_len(u, 10)))
			lputchar('0', &(info->p_b));
		while(arg[j])
			lputchar(arg[j++], &(info->p_b));
	}
	free(arg);
}

void	exa_case(t_flags *flags, t_info *info, char c)
{
	char			*base;
	int				i;
	unsigned int	n;
	int				len;
	char			*tmp;

	i = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	n = va_arg(*(info->args), int);
	len = ft_uns_len(n, 16);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return ;
	tmp[len--] = '\0';
	if (flags->neg)
	{
		while(len > 0)
		{
			tmp[len--] = base[n % 16];
			n /= 16;
		}
		while(i++ < (flags->num - ft_uns_len(n, 16)))
			lputchar('0', &(info->p_b));
	}
	else
	{
		while(i++ < (flags->num - ft_uns_len(n, 16)))
			lputchar('0', &(info->p_b));
		while(len >= 0)
		{
			tmp[len--] = base[n % 16];
			n /= 16;
		}
	}
	lputstr(tmp, &(info->p_b));
	free(tmp);
}
