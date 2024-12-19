/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_dot_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:27:51 by francema          #+#    #+#             */
/*   Updated: 2024/12/19 12:13:21 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	dot_char_case(t_flags *flags, t_info *info)
{
	char	c;
	char	*s;
	int		n_width;

	c = va_arg(*(info->args), int);
	s = ft_strdup(&c);
	n_width = flags->num;
	while (n_width-- > 1)
		lputchar(' ', &(info->p_b));
	lputchar(c, &(info->p_b));
}

void	dot_str_case(t_flags *flags, t_info *info)
{
	char	*s;
	int		n_width;
	int		i;

	s = va_arg(*(info->args), char *);
	n_width = flags->num;
	i = 0;
	while (n_width-- > (int)ft_strlen(s))
		lputchar(' ', &(info->p_b));
	while(s[i] && i < flags->dot)
		lputchar(s[i++], &(info->p_b));
}

void	dot_exa_case(t_flags *flags, t_info *info, char c)
{
	unsigned int	arg;
	char			*s;

	arg = va_arg(*(info->args), int);
	s = malloc(sizeof(char) * (ft_uns_len(arg, 16, 0) + 1));
	if (!s)
		return ;
	if (c == 'x')
		build_num(arg, "0123456789abcdef", s, 0);
	else
		build_num(arg, "0123456789ABCDEF", s, 0);
	if (flags->num > flags->dot && flags->num > (int)ft_strlen(s))
	{
		while (flags->num-- > (int)ft_strlen(s))
			lputchar(' ', &(info->p_b));
	}
	if (flags->dot > (int)ft_strlen(s))
	{
		while (flags->dot-- > (int)ft_strlen(s))
			lputchar('0', &(info->p_b));
	}
	lputstr(s, &(info->p_b));
	free(s);
}

void	dot_ptr_case(t_flags *flags, t_info *info)
{
	void	*ptr;
	char	*s;

	ptr = va_arg(*(info->args), void *);
	s = malloc(sizeof(char) * (ft_uns_len((unsigned long)ptr, 16, 1) + 1));
	if (!s)
		return ;
	build_num((unsigned long)ptr, "0123456789abcdef", s, 1);
	if (flags->num > flags->dot && flags->num > ((int)ft_strlen(s) + 2))
	{
		while (flags->num-- > ((int)ft_strlen(s) + 2))
			lputchar(' ', &(info->p_b));
	}
	lputstr("0x", &(info->p_b));
	if (flags->dot > ((int)ft_strlen(s) + 2))
	{
		while (flags->dot-- > ((int)ft_strlen(s) + 2))
			lputchar('0', &(info->p_b));
		lputstr(s, &(info->p_b));
	}
		lputstr(s, &(info->p_b));
	free (s);
}

void	spec_dot_cases(t_flags *flags, t_info *info, char c)
{
	if (c == 'c')
		dot_char_case(flags, info);
	else if (c == 's')
		dot_str_case(flags, info);
	else if (c == 'x' || c == 'X')
		dot_exa_case(flags, info, c);
	else if (c == 'p')
		dot_ptr_case(flags, info);
}
