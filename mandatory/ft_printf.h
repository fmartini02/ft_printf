/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:49 by francema          #+#    #+#             */
/*   Updated: 2024/12/19 10:39:50 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_info
{
	const char			*s;
	int					i;
	int					p_b;
	unsigned long int	p_tmp;
	unsigned int		u_tmp;
	va_list				*args;
}	t_info;

int		ft_printf(const char *str, ...);
int		check_stdflags(char c);
void	expand_flags(t_info *info);
void	build_num(unsigned long int n, char *base, char *buf, int cast_type);
void	lputchar(char c, int *r);
void	lputstr(char *s, int *r);
void	lputnbr(int n, int *p_b);
void	lputunsigned(unsigned int n, int *p_b);
void	lputexa(t_info *info, char c);
void	lputadrr(t_info *info);
int		ft_skip_num(const char *s, int i);
void	init_info(t_info *info, const char *str, va_list *args);

#endif
