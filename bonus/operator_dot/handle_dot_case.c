/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dot_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:10:14 by francema          #+#    #+#             */
/*   Updated: 2024/12/18 18:09:25 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	handle_dot(t_flags *flags, t_info *info, char c)
{
	int		prec_len;
	int		i;

	prec_len = flags->dot;
	i = 0;
	if (c != 'i' || c != 'd' || c != 'u' )
	{
		if (flags->neg)
			spec_dot_neg_case(flags, info, c);
		else
			spec_dot_cases(flags, info, c);
	}
	else
		put_dot_case(flags, info, c);
	flags->done = 1;
}
