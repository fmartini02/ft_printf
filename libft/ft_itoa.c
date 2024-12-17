/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:38:32 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/27 22:38:32 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*limits_cases(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	return (NULL);
}

void	ft_itoa_utils(long long int n, char *res)
{
	int	len;

	len = ft_len(n);
	res[len--] = '\0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	while (n != 0)
	{
		res[len--] = (n % 10) + 48;
	//	printf("len + 1:%d\n", len + 1);
		n /= 10;
	}
	//printf("res: %s\n", res);
}

char	*ft_itoa(long long int n)
{
	char	*res;

	if (n == INT_MIN || n == INT_MAX)
		return (limits_cases(n));
	else if (n == 0)
		return (ft_strdup("0"));
	else
	{
		res = malloc(ft_len(n) + 1);
		if (!res)
			return (NULL);
		ft_itoa_utils(n, res);
	}
	return (res);
}
/*
int	main()
{
	char	*str;

	// str = ft_itoa(INT_MIN);
	// printf("%s\n", str);
	// free(str);
	// str = ft_itoa(INT_MAX);
	// printf("%s\n", str);
	// free(str);
	// str = ft_itoa(0);
	// printf("%s\n", str);
	// free(str);
	// str = ft_itoa(1234567890);
	// printf("%s\n", str);
	// free(str);
	str = ft_itoa(0);
	printf("%s", str);
	free(str);
	return (0);
}
*/
