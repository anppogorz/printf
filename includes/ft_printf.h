/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:31:10 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/15 15:21:25 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"

typedef struct  s_list
{
    char first;
    char *second;
    char *third;
    char *fourth;
    char option;
}               t_list;

char    *ft_treatment(const char c, va_list ap);
char    *ft_c(char c);
char    *ft_s(char *str);
char    *ft_p(void *ptr);
char    *ft_treatment_p(void *ptr);
char    *ft_d(int i);
char    *ft_i(int i);
char    *ft_u(unsigned int u);
char    *ft_x(unsigned int u);
char    *ft_treatment_x(unsigned int u);
char    *ft_X(unsigned int u);
char    *ft_treatment_X(unsigned int u);
int     ft_strlen_nbr(int i);
int     ft_strlen_nbr_u(unsigned int u);
char    *ft_itoa(int n);
int     ft_printf(const char *format, ...);
char	*ft_itoa_u(unsigned int n);
const char    *ft_skip_flags(const char *s1);
t_list  ft_check_flags(const char *format);
void    ft_display_d(char *str, int car_numbers, t_list flags);
void    ft_display_d_precision(char *str, int car_numbers, int precision, t_list flags);
void    ft_display_s(char *str, int car_numbers, t_list flags);
void    ft_display_s_precision(char *str, int car_numbers, int precision, t_list flags);







#endif
