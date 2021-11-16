/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:41:03 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 12:43:54 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_x(t_flags *s_flags)
{
	if (s_flags->type == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}
