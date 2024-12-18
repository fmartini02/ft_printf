/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:35:41 by francema          #+#    #+#             */
/*   Updated: 2024/12/17 18:51:56 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_utoa_utils(unsigned long long int n, char *res)
{
	int	len;

	len = ft_uns_len(n, 10);
	res[len--] = '\0';
	while (n != 0)
	{
		res[len--] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_utoa(unsigned long long int n)
{
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		s = malloc(ft_uns_len(n, 10) + 1);
		if (!s)
			return (NULL);
		ft_utoa_utils(n, s);
	}
	return (s);
}
