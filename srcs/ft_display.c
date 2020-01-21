/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:25:55 by anpogorz          #+#    #+#             */
/*   Updated: 2020/01/21 07:00:23 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    ft_display(char *str, p_list flags)
{
    int car_numbers;
    int precision;

    precision = -1;
    car_numbers = -1;
    if (flags.second)
        car_numbers = ft_atoi(flags.second);
    if (flags.third == '.')
        precision = ft_atoi(flags.fourth);
    if (flags.second && (precision > 0))
        car_numbers = car_numbers - precision;
   // printf("precision = %d\n", precision);
    //printf("longueur = %d\n", car_numbers);
    //if (flags.option == 'd')
        //ft_display_d(str, car_numbers, flags);
    if (flags.option == 'd' || flags.option == 'u' || flags.option == 'x' || flags.option == 'X')
        ft_display_d_precision(str, car_numbers, precision, flags);
    if (flags.option == 's' || flags.option == 'p' || flags.option == 'c')
        ft_display_s(str, car_numbers, flags);
    if ((flags.option == 's' || flags.option == 'p' || flags.option == 'c') && (precision > 0 || car_numbers > 0))
        ft_display_s_precision(str, car_numbers, precision, flags);
}

void    ft_display_d(char *str, int car_numbers, p_list flags)
{
    char c;

    if (flags.first == '0')
        c = '0';
    else
        c = ' ';
    if (flags.first == '-')
    {
        ft_putstr_fd(str, 1);
        while (car_numbers > 0)
        {
            ft_putchar_fd(c, 1);
            car_numbers--;
        }
    }
    else
    {
        while (car_numbers > 0)
        {
            ft_putchar_fd(c, 1);
            car_numbers--;
        }
        ft_putstr_fd(str, 1);
    }
}

void    ft_display_d_precision(char *str, int car_numbers, int precision, p_list flags)
{
        if (flags.first == '-')
        {
            while (precision > 0)
            {
                ft_putchar_fd('0', 1);
                precision--;
            }
            while ((car_numbers - precision) > 0)
            {
                ft_putchar_fd(' ', 1);
                car_numbers--;
            }
            ft_putstr_fd(str, 1);
        }
        else
        {
            while (precision > 0)
            {
                ft_putchar_fd('0', 1);
                precision--;
                str++;
            }
            while (car_numbers > 0)
            {
                ft_putchar_fd(' ', 1);
                car_numbers--;
            }
            ft_putstr_fd(str, 1);
        }
}

void    ft_display_s(char *str, int car_numbers, p_list flags)
{
    if (flags.first == '-')
    {
        ft_putstr_fd(str, 1);
        while (car_numbers > 0)
        {
            ft_putchar_fd(' ', 1);
            car_numbers--;
        }
    }
    else
    {
        while (car_numbers > 0)
        {
            ft_putchar_fd(' ', 1);
            car_numbers--;
        }
        ft_putstr_fd(str, 1);
    }
}

void    ft_display_s_precision(char *str, int car_numbers, int precision, p_list flags)
{
        if (flags.first == '-')
        {
            while (precision > 0 && *str != '\0')
            {
                ft_putchar_fd(*str, 1);
                precision--;
                str++;
            }
            while ((car_numbers) > 0)
            {
                ft_putchar_fd(' ', 1);
                car_numbers--;
            }
        }
        else
        {
            while (car_numbers > 0)
            {
                ft_putchar_fd(' ', 1);
                car_numbers--;
            }
            while (precision > 0 && *str != '\0')
            {
                ft_putchar_fd(*str, 1);
                precision--;
                str++;
            }
        }
}