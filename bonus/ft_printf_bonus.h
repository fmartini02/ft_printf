/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:49 by francema          #+#    #+#             */
/*   Updated: 2025/03/13 16:42:39 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	num;
	int	zero;
	int	space;
	int	dot;
	int	neg;
	int	pos;
	int	sharp;
	int	done;
	int	dub;
}	t_flags;

typedef struct s_info
{
	const char			*s;
	int					i;
	int					p_b;
	unsigned long int	p_tmp;
	unsigned int		u_tmp;
	va_list				*args;
}	t_info;

/*mandatory funs*/
int		ft_printf(const char *str, ...);
void	expand_flags(t_info *info);
void	lputchar(char c, int *r);
void	lputstr(char *s, int *r);
void	lputnbr(long int n, int *p_b);
void	lputunsigned(unsigned int n, int *p_b);
void	lputexa(unsigned int u, t_info *info, char c);
void	lputadrr(t_info *info);
/*bonus utils*/
void	print_width(int width, int len, t_info *info, t_flags *flags);
void	build_num(unsigned long int n, char *base, char *buf, int cast_type);
int		ft_skip_num(const char *s, int i);
void	init_info(t_info *info, const char *str, va_list *args);
int		init_flags(char c, t_flags *flags, t_info *info, int *i);
int		check_stdflags(char c);
void	ptr_case(void *ptr, t_info *info);
/*dot flag funs*/
void	neg_dot_int_case(t_flags *flags, t_info *info);
void	put_prec_uns_neg(t_flags *flags, t_info *info);
void	dot_int_case(t_flags *flags, t_info *info);
void	put_prec_uns(t_flags *flags, t_info *info);
void	handle_dot(t_flags *flags, t_info *info, char c);
void	spec_dot_neg_case(t_flags *flags, t_info *info, char c);
void	spec_dot_cases(t_flags *flags, t_info *info, char c);
void	put_dot_case(t_flags *flags, t_info *info, char c);
void	put_prec_uns(t_flags *flags, t_info *info);
void	exa_dot_width_greatest(t_flags *flags, t_info *info, char *s);
int		dot_edge_case(t_flags *flags, t_info *info,
			unsigned long int arg, char c);
void	build_exa(char c, char *s, unsigned int arg);
/*width flag funs*/
void	neg_case(t_info *info, char c, t_flags *flags);
void	handle_num(t_info *info, char c, t_flags *flags);
void	num_neg_int_case(t_info *info, t_flags *flags);
void	num_neg_uns_case(t_info *info, t_flags *flags);
void	num_neg_exa_case(t_info *info, t_flags *flags, char c);
void	num_neg_char_case(t_info *info, t_flags *flags);
void	num_neg_str_case(t_info *info, t_flags *flags);
void	num_neg_ptr_case(t_info *info, t_flags *flags);
void	num_char_case(t_info *info, t_flags *flags);
void	num_str_case(t_info *info, t_flags *flags);
void	num_ptr_case(t_info *info, t_flags *flags);
void	num_int_case(t_info *info, t_flags *flags);
void	num_uns_case(t_info *info, t_flags *flags);
void	num_exa_case(t_info *info, t_flags *flags, char c);
/*zero flag funs*/
void	neg_zero_case(t_flags *flags, t_info *info, char c);
void	zero_case(t_flags *flags, t_info *info, char c);
void	handle_zero(t_flags *flags, t_info *info, char c);
void	neg_zero_char_case(t_flags *flags, t_info *info);
void	neg_zero_str_case(t_flags *flags, t_info *info);
void	neg_zero_ptr_case(t_flags *flags, t_info *info);
void	neg_zero_int_case(t_flags *flags, t_info *info);
void	neg_zero_uns_case(t_flags *flags, t_info *info);
void	neg_zero_exa_case(t_flags *flags, t_info *info, char c);
void	zero_char_case(t_flags *flags, t_info *info);
void	zero_str_case(t_flags *flags, t_info *info);
void	zero_ptr_case(t_flags *flags, t_info *info);
void	zero_int_case(t_flags *flags, t_info *info);
void	zero_uns_case(t_flags *flags, t_info *info);
void	zero_exa_case(t_flags *flags, t_info *info, char c);
/*space flag funs*/
void	handle_space(t_info *info, t_flags *flags, char c);
void	space_char(int c, t_info *info, t_flags *flags);
void	space_str(char *s, t_info *info, t_flags *flags);
void	space_adrr(void *p, t_info *info, t_flags *flags);
void	space_hexa(unsigned int n, t_info *info, t_flags *flags, char c);
void	space_uns(unsigned int n, t_info *info, t_flags *flags);
void	space_int(int n, t_info *info, t_flags *flags);
/*sharp flag funs*/
void	handle_sharp(t_info *info, char c, t_flags *flags);
/*pos flag funs*/
void	handle_pos(t_flags *flag, t_info *info, char c);
void	pos_char_case(t_flags *flag, t_info *info);
void	pos_str_case(t_flags *flag, t_info *info);
void	pos_ptr_case(t_flags *flags, t_info *info);
void	pos_int_case(t_flags *flags, t_info *info);
void	pos_uns_case(t_flags *flags, t_info *info);
void	pos_hexa_case(t_flags *flags, t_info *info, char c);
void	neg_pos_char_case(t_flags *flag, t_info *info);
void	neg_pos_str_case(t_flags *flag, t_info *info);
void	neg_pos_ptr_case(t_flags *flags, t_info *info);
void	neg_pos_int_case(t_flags *flags, t_info *info);
void	neg_pos_hexa_case(t_flags *flags, t_info *info, char c);
void	neg_pos_uns_case(t_flags *flags, t_info *info);

#endif
