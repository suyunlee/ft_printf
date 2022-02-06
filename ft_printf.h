/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:54:51 by suylee            #+#    #+#             */
/*   Updated: 2020/12/23 20:37:01 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_options
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	char	type;
	int		index;
}				t_options;

void			save_flag(t_options *specifier, char *format, va_list ap);
void			save_width(t_options *specifier, char *format);
void			save_precision(t_options *specifier, char *format, va_list ap);
void			save_type(t_options *specifier, char *format);
t_options		save_type_specifier(char *format, va_list ap,
				int index, int *fcount);

int				flag(t_options specifier, int count);
void			precision_int(t_options *specifier, int *fcount, int *zcount);
void			precision_str(t_options specifier, char *str, int *fcount);
void			precision_p(t_options *specifier, int *fcount, int *zcount);

int				num_count(int num);
int				hexoctnum_count(unsigned long long unum, char type);
void			print_hexoctnum(unsigned long long unum, char type);
int				unsignednum_count(unsigned int num);
void			print_unsignedint(unsigned int num);
void			print_pnul(t_options specifier, int *fcount, int *zcount);
int				print_intnul(t_options specifier);
void			print_dminus(t_options specifier, int *num,
				int *mcount, int *fcount);
void			print_dminus_two(t_options specifier, int zcount, int *num);
void			print_zcount(t_options specifier, int zcount);

int				print_d(t_options specifier, va_list ap);
int				print_s(t_options specifier, va_list ap);
int				print_c(t_options specifier, va_list ap);
int				print_x(t_options specifier, va_list ap);
int				print_o(t_options specifier, va_list ap);
int				print_u(t_options specifier, va_list ap);
int				print_percent(t_options specifier);
int				print_p(t_options specifier, va_list ap);

int				printf_type(t_options specifier, va_list ap);
int				ft_printf(char *format, ...);

#endif
