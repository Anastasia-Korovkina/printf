/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:23:06 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/17 18:48:33 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	precision;
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
	int	star1;
	int	star2;
}	t_flags;

int		ft_printf(const char *format, ...);
void	ft_init_flags(t_flags *s_flags);
void	ft_check_flags_1(char **format, t_flags	*s_flags);
void	ft_check_flag_width(char **format, t_flags	*s_flags, va_list	*va);
void	ft_check_flag_prec(char **format, t_flags	*s_flags, va_list	*va);
void	ft_check_flag_type(char **format, t_flags	*s_flags);
void	ft_prosessor(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_perc(t_flags *s_flags, int *len);
void	ft_pros_char(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_str(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_int(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_u(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_p(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_x(t_flags *s_flags, va_list	*va, int *len);
void	ft_pros_x_sub4(t_flags *s_flags, int *len, int len_p);
void	ft_pos_int(t_flags *s_flags, int copy_arg, int *len, int len_num);
void	ft_pos_int_sub(t_flags *s_flags, int copy_arg, int *len, int len_num);
void	ft_neg_int(t_flags *s_flags, int copy_arg, int *len, int len_num);
void	ft_zero_int(t_flags *s_flags, int copy_arg, int *len, int len_num);
void	ft_zero_int_sub(t_flags *s_flags, int copy_arg, int *len, int len_num);
char	*ft_strchr(const char *s, int c);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len, int size);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_putx(unsigned int n, int *len, char *hex_base);
size_t	ft_ulen(unsigned int u);
size_t	ft_dlen(int d);
size_t	ft_strlen(const char *s);
size_t	ft_hexlen(unsigned long long int num);
int		ft_atoi(char **format);
char	*ft_check_x(t_flags *s_flags);

#endif