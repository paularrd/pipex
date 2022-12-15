/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/26 11:45:58 by fle-tolg         ###   ########.fr       */
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

static int	ft_fprint_arg(int fd, char c, char s, va_list arguments)
{
	int		r;

	r = 0;
	if (c == '%' && s == 'c')
		r = ft_fprint_char(fd, arguments);
	else if (c == '%' && s == 's')
		r = ft_fprint_str(fd, arguments);
	else if (c == '%' && (s == 'i' || s == 'd'))
		r = ft_fprint_nbr(fd, arguments, 'i');
	else if (c == '%' && s == 'u')
		r = ft_fprint_nbr(fd, arguments, 'u');
	else if (c == '%' && s == 'x')
		r = ft_fprint_nbr(fd, arguments, 'x');
	else if (c == '%' && s == 'X')
		r = ft_fprint_nbr(fd, arguments, 'X');
	else if (c == '%' && s == 'p')
		r = ft_fputaddr(fd, arguments);
	else if (c == '%' && s == '%')
		r = ft_fputper(fd);
	return (r);
}

int	ft_fprintf(int fd, const char *format, ...)
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
			r += ft_fprint_arg(fd, format[i], format[i + 1], arguments);
			i += 2;
		}
		else if (format[i])
		{
			write(fd, &format[i], 1);
			i++;
			r++;
		}
	}
	va_end(arguments);
	return (r);
}
