/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pros_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:15:22 by wbeck             #+#    #+#             */
/*   Updated: 2021/11/13 16:26:32 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_numlen(int num)
// {
// 	int	len;

// 	len = 0;
// 	if (num < 0)
// 	{
// 		num *= -1;
// 		len++;
// 	}
// 	while (num)
// 	{
// 		num /= 10;
// 		len++;
// 	}
// 	return (len);
// }

void	ft_pros_int(t_flags *s_flags, va_list	*va, int *len)
{
	int	copy_arg;
	int	len_num;

	copy_arg = va_arg(*va, int);
	len_num = ft_dlen(copy_arg);
	if (copy_arg > 0)
		ft_pos_int(s_flags, copy_arg, len, len_num);
	else if (copy_arg < 0)
		ft_neg_int(s_flags, copy_arg, len, len_num);
	else
		ft_zero_int(s_flags, copy_arg, len, len_num);
}
