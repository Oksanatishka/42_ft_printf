/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:25:13 by obibik            #+#    #+#             */
/*   Updated: 2018/10/16 12:25:15 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_width(t_param *args)
{
	int		num;
	char	*str;
	char	zero_or_space;

	zero_or_space = ' ';
	if (args->precision > 0 && args->precision < args->l)
		num = args->width - args->precision;
	else if (args->precision == 0 && args->dot)
		num = args->width;
	else
		num = args->width - args->l;
	if (!args->flags.minus && args->flags.zero)
		zero_or_space = '0';
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, zero_or_space, num);
	return (str);
}

static char		*get_precision(t_param *args, char *temp)
{
	char *str;

	if (args->precision > 0 && args->precision < args->l)
		str = ft_strsub(temp, 0, args->precision);
	else if (args->precision == 0 && args->dot)
		str = ft_strnew(0);
	else
		str = ft_strsub(temp, 0, args->l);
	return (str);
}

char			*ft_handle_str(t_param *args, va_list *ap)
{
	char	*res;
	char	*value_to_print;
	char	*prefix_postfix;
	char	*temp;

	if (ft_strcmp(args->length, "l"))
	{
		temp = va_arg(*ap, char *);
		if (!(temp))
			temp = "(null)";
		args->l = ft_strlen(temp);
		value_to_print = get_precision(args, temp);
		prefix_postfix = get_width(args);
		if (args->flags.minus)
			res = ft_strjoin(value_to_print, prefix_postfix);
		else
			res = ft_strjoin(prefix_postfix, value_to_print);
		args->l = ft_strlen(res);
	}
	else
		res = ft_handle_wstr(args, ap);
	return (res);
}
