/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/26 11:37:18 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_is_cs(char c, char s)
{
	if (c != '%')
		return (0);
	if (s == 'c' || s == 's' || s == 'p' || s == 'd'
		|| s == 'i' || s == 'u' || s == 'x'
		|| s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

static int	ft_print_arg(char c, char s, va_list arguments)
{
	int		r;

	r = 0;
	if (c == '%' && s == 'c')
		r = ft_print_char(arguments);
	else if (c == '%' && s == 's')
		r = ft_print_str(arguments);
	else if (c == '%' && (s == 'i' || s == 'd'))
		r = ft_print_nbr(arguments, 'i');
	else if (c == '%' && s == 'u')
		r = ft_print_nbr(arguments, 'u');
	else if (c == '%' && s == 'x')
		r = ft_print_nbr(arguments, 'x');
	else if (c == '%' && s == 'X')
		r = ft_print_nbr(arguments, 'X');
	else if (c == '%' && s == 'p')
		r = ft_putaddr(arguments);
	else if (c == '%' && s == '%')
		r = ft_putper();
	return (r);
}

int	ft_printf(const char *format, ...)
{
	va_list		arguments;
	int			i;
	int			r;

	if (!format)
		return (-1);
	va_start(arguments, format);
	i = 0;
	r = 0;
	while (format[i])
	{
		if (ft_is_cs(format[i], format[i + 1]) == 1)
		{
			r += ft_print_arg(format[i], format[i + 1], arguments);
			i += 2;
		}
		else if (format[i])
		{
			write(1, &format[i], 1);
			i++;
			r++;
		}
	}
	va_end(arguments);
	return (r);
}
