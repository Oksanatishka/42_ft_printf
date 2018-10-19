/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:25:54 by obibik            #+#    #+#             */
/*   Updated: 2018/10/16 12:25:56 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** You must manage the flags #0-+ and space
*/

t_flags		parse_flags(char *fmt, size_t *i)
{
	t_flags res;

	ft_bzero(&res, sizeof(t_flags));
	(*i)++;
	while (fmt[*i] == '+' || fmt[*i] == '-'
			|| fmt[*i] == '#' || fmt[*i] == ' ' ||
			fmt[*i] == '0')
	{
		if (fmt[*i] == '-')
			res.minus = 1;
		if (fmt[*i] == '+')
			res.plus = 1;
		if (fmt[*i] == ' ')
			res.space = 1;
		if (fmt[*i] == '0')
			res.zero = 1;
		if (fmt[*i] == '#')
			res.hashtag = 1;
		(*i)++;
	}
	return (res);
}

/*
** You must manage the minimum field-width
**
** the "*" above means or is used to specify the length of space required
** to print the integer ..and printf now takes two arguments one for space
** and other for integer..
*/

int			parse_width(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int		res;
	size_t	j;

	j = *i;
	while (ft_isdigit(fmt[*i]))
		(*i)++;
	if (fmt[(*i)] == '*')
	{
		res = va_arg(*ap, int);
		if (res < 0)
		{
			res *= -1;
			specif->flags.minus = 1;
		}
		(*i)++;
	}
	else
		res = ft_atoi(fmt + j);
	return (res);
}

/*
** You must manage the precision
*/

int			parse_precision(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int	res;
	int	j;

	res = 0;
	if (fmt[(*i)] == '.')
	{
		specif->dot = 1;
		(*i)++;
		j = *i;
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		if (fmt[(*i)] == '*')
		{
			res = va_arg(*ap, int);
			if (res < 0)
			{
				res *= -1;
				specif->flags.minus = 1;
			}
			(*i)++;
		}
		else
			res = ft_atoi(fmt + j);
	}
	return (res);
}

char		*parse_length(char *fmt, size_t *i)
{
	char	*res;

	res = ft_strnew(2);
	if (fmt[*i] == 'j' || fmt[*i] == 'z' || fmt[*i] == 't' ||
			fmt[*i] == 'L' || fmt[*i] == 'h' || fmt[*i] == 'l')
	{
		*res = fmt[(*i)++];
		if (fmt[*i] == 'l' || fmt[*i] == 'h')
		{
			*(++res) = fmt[(*i)];
			(*i)++;
			res--;
		}
	}
	return (res);
}
