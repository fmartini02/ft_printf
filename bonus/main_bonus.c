/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:47:53 by francema          #+#    #+#             */
/*   Updated: 2024/12/10 11:37:27 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_specflag(t_flags *flags, t_info *info)
{
	const char	*s;
	char		c;

	s = info->s;
	c = s[info->i];//bcs stop before the std flags
	if (flags->zero && !flags->sharp && flags->num && !flags->dot)
		handle_zero(flags, info, c);
	if (flags->space && !flags->pos && !flags->neg)
		handle_space(info, c);
	if (flags->sharp && (c == 'x' || c == 'X'))
		handle_sharp(info, c);
	if (flags->dot)
		handle_dot(flags, info, c);
	if (flags->num)
		handle_num(flags->neg, flags->num, info, c);
	else
		expand_flags(info);
}

void	spec_flag(t_info *info)
{
	int			i;
	t_flags		*flags;
	const char	*s;

	flags = malloc(sizeof(t_flags) * 1);
	if (!flags)
		return ;
	s = info->s;
	i = info->i;
	while(check_stdflags(s[i]))
	{
		init_flags(s[i], flags, info, &i);
		i++;
	}
	handle_specflag(flags, info);
}

void	expand_flags(t_info *info)
{
	const char	*str;
	int			j;

	str = info->s;
	j = info->i;
	if (check_stdflags(str[j]))
		spec_flag(info);
	else if (str[j] == 's')
		lputstr(va_arg(*(info->args), char *), &(info->p_b));
	else if (str[j] == 'c')
		lputchar(va_arg(*(info->args), int), &(info->p_b));
	else if (str[j] == 'd' || str[j] == 'i')
		lputnbr(info, va_arg(*(info->args), int));
	else if (str[j] == 'u')
		lputunsigned(info);
	else if (str[j] == 'x' || str[j] == 'X')
		lputexa(info, str[j]);
	else if (str[j] == 'p')
		lputadrr(info);
	else if (str[j] == '%')
		lputchar('%', &(info->p_b));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_info	*info;
	int		p_b;

	va_start(args, str);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	init_info(info, str, &args);
	while (info->s[info->i])
	{
		if (info->s[info->i] == '%')
		{
			(info->i)++;
			expand_flags(info);
		}
		else
			lputchar(info->s[info->i], &(info->p_b));
		(info->i)++;
	}
	p_b = info->p_b;
	free(info);
	va_end(args);
	return (p_b);
}
/*
int main()
{
	//printf("std %c \n", '0');
	//ft_printf("my %c \n", '0');
	//printf("std %c\n", '0' - 256);
	//ft_printf("my %c\n", '0' - 256);
	//printf("std %c %c %c \n", '0', 0, '1');
	//ft_printf("my %c %c %c \n", '0', 0, '1');
	//printf("std_%c_%c_%c_\n", ' ', ' ', ' ');
	//ft_printf("my_%c_%c_%c_\n", ' ', ' ', ' ');
	printf("std\t%s\n", ".");
	ft_printf("my\t%s\n", ".");
	//printf("printed_b= %d\n", printf("_%u_\n", -1));
	//printf("printed_b= %d\n", ft_printf("_%u_\n", -1));
	//printf("p_b= %d\n", printf("_%p_%p_\n", (void *)LONG_MIN,
	//(void *)LONG_MAX));
	//printf("p_b= %d\n", ft_printf("_%p_%p_\n",
	//(void *)LONG_MIN, (void *)LONG_MAX));
	//printf("_%d_\n", 0);
	//ft_printf("_%d_\n", 0);
	//printf("_%d_\n", -10);
	//ft_printf("_%d_\n", -10);
	//printf("_%x_\n", -10);
	//ft_printf("_%x_\n", -10);
	//printf("_%d_\n", INT_MIN);
	//ft_printf("_%d_\n", INT_MIN);
	//printf("%%\n");
	//ft_printf("%%\n");
} */
//printf("%x", -2147483648)
//printf("%x", 2147483647)
