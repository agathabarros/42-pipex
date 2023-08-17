/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:10:44 by agpereir          #+#    #+#             */
/*   Updated: 2023/05/29 15:17:12 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);

/*----------libftfunctions----------*/
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_itoa(int n);

/*----------std----------*/
int		ft_print_chr(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);

/*----------unsig----------*/
int		ft_print_unsig(unsigned int nbr);

/*----------hex----------*/
int		ft_print_hex(unsigned int n, const char form);

/*----------pointer----------*/
int		ft_print_pointer(unsigned long ptr);

/*----------count----------*/
int		ft_hex_point_len(unsigned long nbr);

#endif
