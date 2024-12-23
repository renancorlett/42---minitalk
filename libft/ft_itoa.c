/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:10:13 by rcorlett          #+#    #+#             */
/*   Updated: 2024/10/23 11:07:24 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function = converts an integer to a string;
//n = number to convert;
//if pointer to the string (SUCCESS)

#include "libft.h"

static	int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = get_num_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len > 0 && str[len - 1] != '-')
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	printf("Result = %s\n", ft_itoa(-2147483648));
	return (0);
}*/
