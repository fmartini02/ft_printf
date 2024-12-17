/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:49:44 by francema          #+#    #+#             */
/*   Updated: 2024/12/17 18:23:34 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_zero(t_flags *flags, t_info *info, char c)
{
	if (c == 'c')
		char_case(flags, info);
	else if (c == 's')
		str_case(flags, info);
	else if (c == 'd' || c == 'i')
		int_case(flags, info);
	else if (c == 'u')
		uns_case(flags, info);
	else if (c == 'x' || c == 'X')
		exa_case(flags, info, c);
	flags->done = 1;
}

void	handle_sharp(t_info *info, char c)
{
	lputstr("0x", &(info->p_b));
	if (c == 'X')
		lputexa(info, c);
	else
		lputexa(info, c);
}

char	*ft_get_adrr(void *ptr)
{
	char	*base;
	char	*BASE;
	char	*tmp;
	int		len;

	base = "0123456789abcdef";
	BASE = "0123456789ABCDEF";
	len = ft_uns_len((unsigned long)ptr, 16);
	tmp = malloc(sizeof(char) * (len + 3));
	if (!tmp)
		return (NULL);
	tmp[len + 2] = '\0';
	tmp[0] = '0';
	tmp[1] = 'x';
	build_num((unsigned long)ptr, base, tmp);
	return (tmp);
}

void	handle_dot(t_flags *flags, t_info *info, char c)
{
	int		prec_len;
	int		i;
	char	*s;
	char	tmp;;

	prec_len = flags->dot;
	i = 0;
	if (c == 's' || c == 'c' || c == 'p' || c == 'x' || c == 'X')
	{
		if (c == 'c')
		{
			tmp = (va_arg(*(info->args), int));
			s = ft_strdup(&tmp);
		}
		else if (c == 's')
			s = ft_strdup((va_arg(*(info->args), char *)));
		else if (c == 'p')
			s = ft_get_adrr(va_arg(*(info->args), void *));
		while(i < prec_len && s[i])
			lputchar(s[i++], &(info->p_b));
		free(s);
	}
	else
		put_prec(flags, info, c);
	flags->done = 1;
}
