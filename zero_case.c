/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:41:10 by francema          #+#    #+#             */
/*   Updated: 2024/12/03 16:18:43 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_case(t_flags *flags, t_info *info, char *ret)
{
	int	n;
	int	i;

	n = va_arg(*(info->args), int);
	i = 0;
	if (flags->neg)
	{
		ret[i++] = n;
		while (i < flags->num)
			ret[i++] = ' ';
		ret[i] = '\0';
	}
	else
	{
		while (i < flags->num - 1)
			ret[i++] = ' ';
		ret[i] = n;
		ret[i + 1] = '\0';
	}
	return (ret);
}

char	*str_case(t_flags *flags, t_info *info, char *ret)
{
	char	*arg;
	int		i;

	i = 0;
	arg = va_arg(*(info->args), char *);
	if (flags->neg)
	{
		while(arg[i])
		{
			ret[i] = arg[i];
			i++;
		}
		while (i < flags->num)
			ret[i++] = ' ';
		ret[i] = '\0';
	}
	else
	{
		while(i < (flags->num - ft_strlen(arg)))
			ret[i] = ' ';
		while(*arg)
			ret[i++] = (*arg)++;
		ret[i] = '\0';
	}
	return (ret);
}

char	*int_case(t_flags *flags, t_info *info, char *ret)
{
	int		n;
	int		i;
	char	*arg;

	n = va_arg(*(info->args), int);
	arg = ft_itoa(n);
	i = 0;
	if (flags->neg)
		int_case_utils(flags, info, ret, arg);
	else
	{
		if (flags->pos)
			int_case_utils2(flags, info, ret, arg);
		else
		{
			while (i < (flags->num  - ft_strlen(arg)))
				ret[i++] = '0';
			while (*arg)
				ret[i++] = (*arg)++;
		}
		ret[i] = '\0';
	}
	free(arg);
	return (ret);
}

char	*uns_case(t_flags *flags, t_info *info, char *ret)
{
	unsigned int	u;
	char			*arg;
	int				i;

	u = va_arg(*(info->args), unsigned int);
	arg = ft_itoa((long long int)u);
	i = 0;
	if (flags->neg)
	{
		i -= 1;
		while(arg[++i])
			ret[i] = arg[i];
		while(i < flags->num)
			ret[i++] = '0';
	}
	else
	{
		while(i < (u - ft_num_len(u, 10)))
			ret[i++] = '0';
		while(*arg)
			ret[i++] = (*arg)++;
	}
	ret[i] = '\0';
	free(arg);
	return (ret);
}
