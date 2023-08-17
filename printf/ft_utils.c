/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:45:22 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/29 18:13:07 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

char	*ft_strchr(const char *str, int c)
{
	char	aux;
	int		i;

	i = 0;
	aux = (char)c;
	while (str[i] != '\0' && str[i] != aux)
		i++;
	if (str[i] == aux)
		return (& ((char *)str)[i]);
	return (NULL);
}
