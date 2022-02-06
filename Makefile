# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 15:26:14 by suylee            #+#    #+#              #
#    Updated: 2020/12/11 15:16:31 by suylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rc

INCS		= -I. -I./libft
SRCS		= ft_printf.c ft_print_type.c ft_print_type_two.c save_type_specifier.c\
			  ft_printf_utils.c ft_printf_untils_two.c ft_type_specifier.c
OBJS		= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS) libftmk
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)

libftmk		:
			@$(MAKE) -C ./libft all

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

clean :
		@$(MAKE) -C ./libft clean
		@$(RM) $(OBJS)

fclean : clean
		@$(MAKE) -C ./libft fclean
		@$(RM) $(NAME)

re : fclean all
.PHONY : all clean fclean re libftmk
