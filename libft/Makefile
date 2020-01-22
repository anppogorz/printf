# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 08:26:03 by anpogorz          #+#    #+#              #
#    Updated: 2020/01/15 07:22:36 by anpogorz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./ft_atoi.c ./ft_display.c ./ft_itoa.c ./ft_itoa_u.c ./ ft_printf.c \
          ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_strdup.c ./ft_strlen.c \
          ./ft_strncmpc.c ./ ft_treatment_c_s_p_d.c ./ft_treatment_x_X.c \
          ./treatment.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I. -c

all:		${NAME} 

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		re fclean clean
