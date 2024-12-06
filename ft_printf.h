/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:49 by francema          #+#    #+#             */
/*   Updated: 2024/12/03 16:21:34 by francema         ###   ########.fr       */
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
	int	num;
	int	zero;
	int	space;
	int	dot;
	int	neg;
	int	pos;
	int	sharp;
	/*int	ptr;*/
}	t_flags;

int		ft_printf(const char *str, ...);
void	lputchar(char c, int *r);
void	lputstr(char *s, int *r);
void	lputnbr(t_info *info, int n);
void	lputunsigned(t_info *info);
void	lputexa(t_info *info, char c);
void	lputadrr(t_info *info);
int		ft_skip_num(char *s, int i);
void	init_info(t_info *info, char *str, va_list *args);
char	*char_case(t_flags *flags, t_info *info, char *ret);
char	*str_case(t_flags *flags, t_info *info, char *ret);
char	*int_case(t_flags *flags, t_info *info, char *ret);
char	*uns_case(t_flags *flags, t_info *info, char *ret);
void	int_case_utils(t_flags *flags, t_info *info, char *ret, char *arg);
void	int_case_utils2(t_flags *flags, t_info *info, char *ret, char *arg);
#endif
