/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:49 by francema          #+#    #+#             */
/*   Updated: 2024/12/10 16:54:21 by francema         ###   ########.fr       */
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
void	expand_flags(t_info *info);
void	build_num(unsigned long int n, char *base, char *buf);
void	lputchar(char c, int *r);
void	lputstr(char *s, int *r);
void	lputnbr(t_info *info, int n);
void	lputunsigned(t_info *info);
void	lputexa(t_info *info, char c);
void	lputadrr(t_info *info);
int		ft_skip_num(const char *s, int i);
void	init_info(t_info *info, const char *str, va_list *args);
void	init_flags(char c, t_flags *flags, t_info *info, int *i);
void	char_case(t_flags *flags, t_info *info);
void	str_case(t_flags *flags, t_info *info);
void	int_case(t_flags *flags, t_info *info);
void	uns_case(t_flags *flags, t_info *info);
void	int_neg_case(t_flags *flags, t_info *info, char *arg);
void	int_pos_case(t_info *info, char *arg);
void	handle_zero(t_flags *flags, t_info *info, char c);
void	handle_space(t_info *info, char c);
void	handle_sharp(t_info *info, char c);
void	handle_dot(t_flags *flags, t_info *info, char c);
void	handle_num(int width, t_info *info, char c);
void	print_width(int width, int len, t_info *info);
void	neg_case(int width, t_info *info, char c);
void	neg_magic_ptr(void *ptr, int width, t_info *info);
void	neg_magic_uns(unsigned int uns, char c, int width, t_info *info);
void	neg_magic_char(int n, int width, t_info *info);
void	neg_magic_num(char *arg, int width, t_info *info);
void	ptr_case(unsigned long nu, t_info *info);
void	magic_ptr(void *ptr, int width, t_info *info);
void	magic_uns(unsigned int uns, char c, int width, t_info *info);
void	magic_char(int n, int width, t_info *info);
void	magic_num(char *arg, int width, t_info *info);
int		check_stdflags(char c);
void	put_precision(t_flags *flags, t_info *info, char c);

#endif
