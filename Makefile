# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 08:26:03 by anpogorz          #+#    #+#              #
#    Updated: 2020/02/06 13:11:44 by anpogorz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/ft_atoi.c ./srcs/ft_dispatch.c ./srcs/ft_display_num.c \
          ./srcs/ft_display_string.c ./srcs/ft_itoa.c ./srcs/ft_itoa_u.c \
          ./srcs/ft_printf.c ./srcs/ft_printf_utils.c \
          ./srcs/ft_treatment_c_s_p_d.c ./srcs/ft_treatment_x_X.c \
		  ./srcs/treatment.c ./srcs/flags_utils.c ./srcs/ft_display_pourcent.c \
		  ./srcs/ft_display_c.c ./srcs/ft_display_d.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I./includes -c

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
