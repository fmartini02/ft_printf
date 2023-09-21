/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:59:24 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:57 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"ft_printf.h"

int	ft_putchar_n(char c)
{
	int	n;

	n = 0;
	write(1, &c, 1);
	n++;
	return (n);
}
int ft_special_flags(va_list args, const char **str, int *n)
{
    int i;
    int t;
    char *str_flag;
    
    i = 0;
    t = 0;
    if (**str == '%')
       i += ft_putchar_n('%');
    else if (**str == '0')
    {
        (*str)++;
        while(**str >= 0 && **str <= 9)
        {
            str_flag[i] = **str;
            i++;
            (*str)++;
        }
        t = ft_atoi_flag(str_flag, va_arg(args, int));
        
    }

}
int	ft_hadle_flags(va_list args, const char **str, int *n)
{
	int	i;

	i = 0;
	(*str)++;
	if(**str == '%' || **str == '0' || **str == '-' 
			|| **str == '+' || **str == '#' || **str == '.')
		i = ft_special_flags(args, str, n);
	else if(**str == 's')
	{
		ft_putstr_n(va_arg(args, char *), n);
		i += 2;
	}
	else if(**str == 'd' || **str == 'i')
	{
		ft_putnbr(va_arg(args, int), n);
		i += 2;
	}
	else if(**str == 'u')
	{
		ft_punt_uns(va_arg(args, unsigned int), n);
		i += 2;
	}
	else if(**str == 'x')
	{
		ft_putnbr_base(va_arg(args, unsigned int), n, "0123456789abcdef");
		i += 2;
	}
	else if(**str == 'X')
	{
		ft_putnbr_base(va_arg(args, unsigned int), n, "0123456789ABCDEF");
		i += 2;
	}
	else if(**str == 'p')
	{
		ft_putnbr_base(va_arg(args, unsigned int), n, "0123456789abcdef");
		i += 2;
	}
	else if(**str == '%')
	{
		i += ft_putchar_n('%');
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		n;
	int		i; //da usare per il return di ft_handle_flags

	va_start(args, str);
	n = 0;
	while(*str)
	{
		if(*str == ' ')
			n += ft_putchar_n(*str);
		else if(*str == '%')
			i = ft_hadle_flags(args, &str, &n);
		while(i--)
			n += ft_putchar_n(*str);
		else
			n += ft_putchar_n(*str);
	}

}