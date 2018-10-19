/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:26:32 by obibik            #+#    #+#             */
/*   Updated: 2018/10/16 12:26:34 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_mem(t_param *args)
{
	if (!args)
		return ;
	ft_strdel(&(args->length));
	ft_memdel((void **)&args);
}

t_param	*parse_params(char *fmt, va_list *ap, size_t *i)
{
	t_param *res;

	res = malloc(sizeof(t_param));
	ft_bzero(res, sizeof(t_param));
	res->flags = parse_flags(fmt, i);
	res->width = parse_width(fmt, i, ap, res);
	res->precision = parse_precision(fmt, i, ap, res);
	res->length = parse_length(fmt, i);
	res->specifier = fmt[(*i)];
	return (res);
}

size_t	size_of_final_str(char *fmt, va_list *ap)
{
	t_param *param;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			param = parse_params((char*)fmt, ap, &i);
			size = size + ft_algo(param, ap);
			del_mem(param);
		}
		else
		{
			write(1, (fmt + i), 1);
			size++;
		}
		i++;
	}
	return (size);
}

/*
** main function : printf will return the total len of chars displayed by printf
** va_list - Variable Argument Lists
** Whenever a function is declared to have an indeterminate number of arguments,
** in place of the last argument you should place an ellipsis (which looks
** like '...'), so, int a_function ( int x, ... ); would tell the compiler the
** function should accept however many arguments that the programmer uses, as
** long as it is equal to at least one, the one being the first, x.
**
** va_start is a macro which accepts two arguments, a va_list and the name of
** the variable that directly precedes the ellipsis ("...").
**
** va_end cleans up the variable argument list.
*/

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, fmt);
	size = (int)size_of_final_str(fmt, &ap);
	va_end(ap);
	return (size);
}
