/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:49 by francema          #+#    #+#             */
/*   Updated: 2024/11/27 19:14:06 by francema         ###   ########.fr       */
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
# include "libft/libft.h"

typedef struct s_info
{
	const char			*s;
	int					i;
	int					p_b;
	unsigned long int	p_tmp;
	unsigned int		u_tmp;
	va_list				*args;
}	t_info;

typedef struct s_flags
{
	int	neg;
	int	pos;
	int	space;
	int	sharp;
	int	zero;
	int	dot;
}	t_flags;

void	lputchar(char c, int *r);
void	lputstr(char *s, int *r);
void	lputnbr(t_info *info, int n);
void	lputexa(t_info *info, char c);
void	lputadrr(t_info *info);
int		ft_printf(const char *str, ...);
void	lputunsigned(t_info *info);

#endif
