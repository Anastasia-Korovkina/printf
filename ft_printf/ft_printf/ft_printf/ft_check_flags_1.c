/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:37:23 by wbeck             #+#    #+#             */
/*   Updated: 2021/10/20 08:34:11 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags_1(char **format, t_flags	*s_flags)
{
	while (ft_strchr("+-0 #", *(++(*format))))
	{
		if (**format == ' ')
			s_flags->space = 1;
		if (**format == '+')
			s_flags->plus = 1;
		if (**format == '-')
			s_flags->minus = 1;
		if (**format == '#')
			s_flags->hash = 1;
		if (**format == '0')
			s_flags->zero = 1;
	}
}
/*
void	ft_check_flags_1(char **format, t_flags	*s_flags)
{
	while (1)//(ft_strchr("+-0 #", *(++(*format))))
	{
		if (**format == ' ')
			s_flags->space = 1;
		else if (**format == '+')
			s_flags->plus = 1;
		else if (**format == '-')
			s_flags->minus = 1;
		else if (**format == '#')
			s_flags->hash = 1;
		else if (**format == '0')
			s_flags->zero = 1;
		else
			return ;
	}
}
*/